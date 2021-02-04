# a simple makefile

```
dirMingw64 := /d/mingw64
dirMingw64Include := /d/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include
dirMingw64Include += $(dirMingw64Include)/c++
dirInclude := ./source 
dirInclude += $(dirMingw64Include)
dirSource := ./source
dirObject := ./object
dirSharedLib := ./source
dirSharedLib += /c/Windows/SysWOW64
dirSharedLib += /c/Windows/System32
dirStaticLib := ./source

$(shell mkdir -p $(dirObject))

source := $(foreach dir, $(dirSource), $(wildcard $(dir)/*.c[pp]?))
#object := $(patsubst %.c, $(dirObject)/%.o, $(notdir $(source)))
object += $(patsubst %.cpp, $(dirObject)/%.o, $(notdir $(source)))
dependence := $(object:.o=.d)
#sharedLib := $(dirSharedLib)/icsneo.dll
sharedLib := $(foreach singleLib, $(dirSharedLib), $(singleLib)/icsneo40.dll)
staticLib := $(dirStaticLib)/libcgw.a

flagInclude := $(foreach dir, $(dirInclude), -I$(dir))
flagSharedLib := $(foreach singleLib, $(sharedLib), -L$(singleLib))

CC := g++
CFLAGS := -g -W  $(flagInclude) $(flagSharedLib) 
CFLAGS += -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic
target = all

$(target):$(object)
	$(CC) -o $@ $^ $(staticLib) $(CFLAGS)

$(dirObject)/%.o:$(dirSource)/%.c[pp]?
	$(CC) -o $@ -c $< $(CFLAGS)

$(dirObject)/%.d:$(dirSource)/%.c[pp]?
	$(createDependence)

.PHONY:clean
clean:
	-rm -f $(target) $(object) $(dependence) $(dirObject)/*.d.*
	-rm -rf $(dirObject)

-include ./source/makefile
-include $(dependence)

define createDependence
@set -e; rm -f $@; \
$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
sed 's,\($*\).o[ :]*,$(dir $@)\1.o $@ : ,g' < $@.$$$$ > $@; \
rm -f $@.$$$$
endef

#export $(dirInclude)
#export $(flagInclude) 
#export $(dirSource) 
#export $(dirObject) 
#export $(source) 
#export $(object) 
#export $(dependence) 
#export $(createDependence)

test:
	@echo dirInclude = $(dirInclude)
	@echo flagInclude = $(flagInclude)
	@echo dirSource = $(dirSource)
	@echo dirObject = $(dirObject)
	@echo source = $(source)
	@echo object = $(object)
	@echo dependence = $(dependence)
	@echo mingw64 = $(mingw64)
	@echo dirMingw64 = $(dirMingw64)
	@echo dirSharedLib = $(dirSharedLib)
	@echo flagSharedLib = $(flagSharedLib)
	@echo dirStaticLib = $(dirStaticLib)
	@echo flagStaticLib = $(flagStaticLib)
```
