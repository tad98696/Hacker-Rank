SUBDIRS := $(wildcard */.)
TOPTARGETS := all clean test

.PHONY: all
all: $(SUBDIRS)

.PHONY: $(TOPTARGETS)
$(TOPTARGETS): $(SUBDIRS)

.PHONY: $(SUBDIRS)
$(SUBDIRS):
	echo $@
	$(MAKE) -C $@ $(MAKECMDGOALS)
