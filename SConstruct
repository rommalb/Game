import os

AddOption('--sfmlDir',
  default='#contrib',
  help='Extracted local directory for SFML')
AddOption('--projects',
  action='store_true',
  help='Create visual studio project file')
  
# Make required directories
dirs = ['build', 'projects']
for dir in dirs:
  try:
   os.makedirs(dir)
  except OSError:
    pass

#Build Environment
env = Environment(CPPPATH='#include', TARGET_ARCH='i386')

env['LIBPATH'] = [os.path.join(GetOption('sfmlDir'), 'lib')]
env.Append(CPPFLAGS=['/EHsc'])

outdir='build'

allFiles = SConscript('src/SConscript', exports='env', variant_dir=outdir, duplicate=0)

#project files
if GetOption('projects'):
  relativeSrcPaths = map(lambda f: f.srcnode().path, allFiles)
  relativeToProjectDir = map(lambda f: os.path.relpath(f, 'projects'), relativeSrcPaths)
  env.MSVSProject(target = 'projects/Game' + env['MSVSPROJECTSUFFIX'], srcs=relativeToProjectDir, variant='default')