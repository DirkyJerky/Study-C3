#define println(X) std::cout << X << std::endl

#define demo_int(X) printf( #X " -> %d\n", (X) )
const char *___ret;
bool ___retb;
#define demo_string(X) ___ret = (X); printf( #X " -> \"%s\"\n", ((___ret == NULL) ? "NULL" : ___ret) )
#define demo_float(X) printf( #X " -> %f\n", (X) )
#define demo_void(X) printf( #X "\n" ); X
#define demo_char(X) printf( #X " -> \"%c\"\n", (X) )
#define demo_pointer(X) printf( #X " -> \"%p\"\n", (X) )
#define demo_bool(X) ___retb = (X); printf( #X " -> %s\n", ((___retb) ? "true" : "false" ))

#define demo(X) demo_int(X)
