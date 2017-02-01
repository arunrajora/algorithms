import sys,os

root = "./codes/"

for path, subdirs, files in os.walk(root):
	print "processing : "+path
	print "\tfound "+str(len(files)+len(subdirs))+" files."
	mapperFile=open(path+"/mapper.txt","w+")
	for dir in subdirs:
		print "\t\tadding directory : "+dir
		mapperFile.write(dir+"\n");
	for file in files:
		if(file!="mapper.txt"):
			print "\t\tadding file : "+file
			mapperFile.write(file+"\n");
		else:
			print "\t\tskipping mapper file."
	mapperFile.close();