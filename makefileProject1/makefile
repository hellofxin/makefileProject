dirInclude := ./main ./user
dirSource := ./main ./user
dirObject := ./object

source := $(foreach dir, $(dirSource), $(wildcard $(dir)/*.c))
object := $(patsubst %.c, $(dirObject)/%.o, $(notdir $(source)))
dependence := $(object:.o=.d)

flagInclude := $(foreach dir, $(dirInclude), -I$(dir))

CC := g++
CFLAGS := -g -Wall $(flagInclude)
target = all

$(target):$(object) 
	$(CC) -o $@ $(CFLAGS) $^

.PHONY:clean
clean:
	-rm -f $(target) $(object) $(dependence)

-include ./main/makefile
-include ./user/makefile
-include $(dependence)

define createDependence
@set -e; rm -f $@; \
$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
sed 's,\($*\).o[ :]*,$(dir $@)\1.o $@ : ,g' < $@.$$$$ > $@; \
rm -f $@.$$$$
endef

export $(dirInclude)
export $(flagInclude) 
export $(dirSource) 
export $(dirObject) 
export $(source) 
export $(object) 
export $(dependence) 
export $(createDependence)

test:
	@echo dirInclude = $(dirInclude)
	@echo flagInclude = $(flagInclude)
	@echo dirSource = $(dirSource)
	@echo dirObject = $(dirObject)
	@echo source = $(source)
	@echo object = $(object)
	@echo dependence = $(dependence)

