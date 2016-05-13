#! python2

#import pycurl
#from StringIO import StringIO
#
#buffer = StringIO()
#c = pycurl.Curl()
#c.setopt(c.URL, 'http://www.sfml-dev.org/files/SFML-2.3.2-windows-vc12-32-bit.zip')
#c.setopt(c.WRITEDATA, buffer)
#c.perform
#c.close()
#
#body = buffer.getvalue()
#
#
#f = open('test.zip', 'w')
#f.write(buffer.getvalue())
#f.close()

#import urllib2
#response = urllib2.urlopen('http://www.sfml-dev.org/files/SFML-2.3.2-windows-vc12-32-bit.zip')
#
#f = open('test.zip', 'w')
#f.write(response.read())
#f.close()

from zipfile import ZipFile
from urllib import urlretrieve
import tempfile
import os
from distutils.dir_util import copy_tree
import subprocess
import shutil


def fileTypeExist(extn, dir):
	if not os.path.exists(dir):
		return False

	filenames = os.listdir(dir)
	for filename in filenames:
		if filename.endswith(extn):
			return True
	return False

def downloadZipToTempDir(theurl):
	print("Downloading from " + theurl)

	tempZip = tempfile.mkstemp('.zip')
	destDir = tempfile.mkdtemp()
	name, hdrs = urlretrieve(theurl, tempZip[1])
	thefile = ZipFile(tempZip[1])
	thefile.extractall(destDir)
	thefile.close()
	os.close(tempZip[0])
	os.remove(tempZip[1])
	
	return destDir

def downloadPremake():
	premakeFilePath = os.path.join(os.getcwd(), 'premake5.exe')
	if os.path.isfile(premakeFilePath):
		print("No need to download premake.")
		return

	destDir = downloadZipToTempDir('https://github.com/premake/premake-core/releases/download/v5.0.0-alpha8/premake-5.0.0-alpha8-windows.zip')
	premakeDir = os.path.join(destDir, 'premake5.exe')
	shutil.copy2(premakeDir, os.getcwd())
	
	if os.path.exists(destDir):
		shutil.rmtree(destDir)


def downloadSFML(dllDestDirs, libDestDirs):
	if not dllDestDirs and not libDestDirs:
		print("No need to download SFML.")
		return 

	theurl = 'http://www.sfml-dev.org/files/SFML-2.3.2-windows-vc12-32-bit.zip'
	destDir = downloadZipToTempDir(theurl)

	binFromDirectory = os.path.join(destDir, 'SFML-2.3.2', 'bin')
	libFromDirectory = os.path.join(destDir, 'SFML-2.3.2', 'lib')

	for dir in dllDestDirs:
		if not os.path.exists(dir):
			os.makedirs(dir)
		print("copying dlls to " + dir)
		copy_tree(binFromDirectory, dir)

	for dir in libDestDirs:
		if not os.path.exists(dir):
			os.makedirs(dir)
		print("copying libs to " + dir)
		copy_tree(libFromDirectory, dir)

	if os.path.exists(destDir):
		shutil.rmtree(destDir)


# make build/bin/debug and /release folders if necessary
def main():
	# set up all the requisite directories
	build_dir = os.path.join(os.getcwd(), 'build', 'bin')
	debug_dir = os.path.join(build_dir, 'debug')
	release_dir = os.path.join(build_dir, 'release')
	lib_dir = os.path.join(os.getcwd(), 'contrib', 'SFML-2.3.2', 'lib')

	# download the premake exe if necessary
	downloadPremake()
	
	# store the dll and lib destinations that don't have what they need
	dllDirs = []
	libDirs = []
	
	# check if the debug and release directories have the dlls,
	# and add to the list if necessary
	if not fileTypeExist('.dll', debug_dir):
		print("Debug dir does not have dlls")
		dllDirs.append(debug_dir)
	if not fileTypeExist('.dll', release_dir):
		print("Release dir does not have dlls")
		dllDirs.append(release_dir)

	# check if the contrib directory has the sfml libs, and add to the list if necessary
	if not fileTypeExist('.lib', lib_dir):
		print("Lib dir does not have sfml libs")
		libDirs.append(lib_dir)
	
	# download any necessary sfml components to the correct directories
	downloadSFML(dllDirs, libDirs)

	# copy the font file to the correct directory
	print("Copying font file.")
	shutil.copy('arial.ttf', debug_dir)
	shutil.copy('arial.ttf', release_dir)

	# run premake
	subprocess.call("premake5.exe vs2013", shell=True)


if __name__ == '__main__':
	main()
