SRCS     = $(shell find src -name '*.cpp')
OBJS     = ${SRCS:.cpp=.o}
DEPS     = ${OBJS:.o=.d}
INCFLAGS = -Isrc
CPPFLAGS += -O0
LIB      = libut.a

# OS X
CXX        = clang++
STATIC_LIB = libtool -o
OBJ_FLAGS  = -MD
CPPFLAGS   += -std=c++11 -stdlib=libc++

.SUFFIXES:
.SUFFIXES: .cpp .o .d

-include $(DEPS)

%.o: %.cpp
	$(CXX) $(INCFLAGS) $(CPPFLAGS) $(OBJ_FLAGS) -o $@ -c $<

all: $(LIB)

$(LIB): $(OBJS)
	$(STATIC_LIB) obj/$(LIB) $(OBJS)

test: $(LIB)
	$(CXX) $(INCFLAGS) $(CPPFLAGS) -o obj/test tests/main.cpp obj/$(LIB)

clean:
	rm -rf $(OBJS)
	rm -rf $(DEPS)
	rm -rf obj/*
