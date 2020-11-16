#dirInclude += ./main 
#flagInclude := $(foreach dir, $(dirInclude), -I$(dir))
#dirSource += ./main 
#dirObject ?= ./object

#source := $(foreach dir, $(dirSource), $(wildcard $(dir)/*.c))
#object := $(patsubst %.c, $(dirObject)/%.o, $(notdir $(source)))
#dependence := $(object:.o=.d)

#-include $(dependence)

#CC ?= g++
#CFLAGS := -g -Wall $(flagInclude)

$(dirObject)/%.o:./main/%.c
	$(CC) -o $@ $(CFLAGS) -c $< 

$(dirObject)/%.d:./main/%.c
	$(createDependence)
