CXX			= g++
CXXFLAGS	= -Wall	-std=c++17	-Iinclude	-MMD	-MP

# 공유 소스들
LIB_SRCS	= src/math_utils.cpp src/Person.cpp
LIB_OBJS	= $(LIB_SRCS:src/*.cpp=build/*.o)

# 프로그램별 실행 파일
APPS		= build/main_math build/main_maxOf	build/main_person

all: $(APPS)

build/main_math:	build/main_math.o	build/math_utils.o
	$(CXX)	$^ -o $@

build/main_maxOf:	build/main_maxOf.o
	$(CXX)	$^ -o $@

build/main_person:	build/main_person.o	build/Person.o
	$(CXX)	$^ -o $@


# 공통 규칙 설정: src/와 apps/ 양쪽의 .cpp를 .o로 변환
build/%.o:	src/%.cpp
	@mkdir -p build
	$(CXX)	$(CXXFLAGS)	-c	$<	-o	$@

build/%.o:	apps/%.cpp
	@mkdir -p build
	$(CXX)	$(CXXFLAGS)	-c	$<	-o	$@

clean:
	rm -rf build

.PHONY: all clean

-include $(wildcard build/*.d)