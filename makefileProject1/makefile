dirInclude := ./main ./user
flagInclude := $(foreach dir, $(dirInclude), -I$(dir))
dirSource := ./main ./user
dirObject := ./object

source := $(foreach dir, $(dirSource), $(wildcard $(dir)/*.c))
object := $(patsubst %.c, $(dirObject)/%.o, $(notdir $(source)))
dependence := $(object:.o=.d)

CC := g++
CFLAGS := -g -Wall $(flagInclude)
target = all
$(target):$(object) 
	$(CC) -o $@ $(CFLAGS) $^

#$(dirObject)/%.o:$(foreach dir, $(dirSource), $(dir)/%.c)
#	$(CC) $(CFLAGS) -c $< -o $@

$(dirObject)/%.o:./main/%.c
	$(CC) -o $@ $(CFLAGS) -c $< 

$(dirObject)/%.o:./user/%.c
	$(CC) -o $@ $(CFLAGS) -c $< 

-include $(dependence)

$(dirObject)/%.d:./main/%.c
	$(createDependence)
	
$(dirObject)/%.d:./user/%.c
	$(createDependence)

.PHONY:clean

clean:
	-rm -f $(target) $(object) $(dependence)

define createDependence
@set -e; rm -f $@; \
$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
sed 's,\($*\).o[ :]*,$(dir $@)\1.o $@ : ,g' < $@.$$$$ > $@; \
rm -f $@.$$$$
endef

test:
	@echo dirInclude = $(dirInclude)
	@echo flagInclude = $(flagInclude)
	@echo dirSource = $(dirSource)
	@echo dirObject = $(dirObject)
	@echo source = $(source)
	@echo object = $(object)
	@echo dependence = $(dependence)

