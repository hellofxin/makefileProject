#dirInclude += ./user
#flagInclude := $(foreach dir, $(dirInclude), -I$(dir))
#dirSource += ./user
#dirObject ?= ./object

#source := $(foreach dir, $(dirSource), $(wildcard $(dir)/*.c))
#object := $(patsubst %.c, $(dirObject)/%.o, $(notdir $(source)))
#dependence := $(object:.o=.d)

#-include $(dependence)

#CC ?= g++
#CFLAGS := -g -Wall $(flagInclude)

$(dirObject)/%.o:./user/%.c
	$(CC) -o $@ $(CFLAGS) -c $< 

$(dirObject)/%.d:./user/%.c
	$(createDependence)
