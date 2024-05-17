all: choc mx
	
choc:
	python3 klavyl.py --choc
	mv *.stl stl_choc/

mx:
	python3 klavyl.py --mx
	mv *.stl stl_mx/
