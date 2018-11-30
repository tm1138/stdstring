all:
	g++ main.cc stdstring_ctor.cc stdstring_traits.cc stdstring_find.cc -o test
clean:
	rm -rf test
