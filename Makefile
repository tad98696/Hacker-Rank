SUBDIRS := $(wildcard */.)
TOPTARGETS := all clean test veryclean

.PHONY: all
all: $(SUBDIRS)

.PHONY: $(TOPTARGETS)
$(TOPTARGETS): $(SUBDIRS)

.PHONY: $(SUBDIRS)
$(SUBDIRS):
	@echo "Entering: $(@D)"
	@$(MAKE) -C $@ $(MAKECMDGOALS)
	@echo "Leaving: $(@D)"
