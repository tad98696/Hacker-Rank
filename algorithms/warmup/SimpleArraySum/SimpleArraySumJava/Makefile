include ../../../../Makefile.work

ifeq (Windows, $(findstring Windows, $(OS)))
	export OUTPUT_PATH = stdout
else
	export OUTPUT_PATH = "/dev/stdout"
endif

test: workaround

workaround:
	@if [ "stdout" == $(OUTPUT_PATH) ] && \
	    [ $$(grep "$(DIRNAME) | dos2unix" $(DIRNAME).exe | wc -l) -gt 0 ]; \
	  then \
	  sed -e 's/\( | dos2unix\)//' \
	      -e 'acat $(OUTPUT_PATH) | dos2unix' \
	      -e 'arm $(OUTPUT_PATH)' \
	      $(DIRNAME).exe -i; \
	fi
