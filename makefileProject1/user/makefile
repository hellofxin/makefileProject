dirInclude ?= ./main ./user
flagInclude := $(foreach dir, $(dirInclude), -I$(dir))
dirSource ?= ./main ./user
dirObject ?= ./object

source := $(foreach dir, $(dirSource), $(wildcard $(dir)/*.c))
object := $(patsubst %.c, $(dirObject)/%.o, $(notdir $(source)))
dependence := $(object:.o=.d)

CC ?= g++
CFLAGS ?= -g -Wall $(flagInclude)

$(dirObject)/%.o:./user/%.c
	$(CC) -o $@ $(CFLAGS) -c $< 

-include $(dependence)

$(dirObject)/%.d:./user/%.c
	$(createDependence)
	
define createDependence
@set -e; rm -f $@; \
$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
sed 's,\($*\).o[ :]*,$(dir $@)\1.o $@ : ,g' < $@.$$$$ > $@; \
rm -f $@.$$$$
endef

