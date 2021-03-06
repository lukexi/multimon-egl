
#if !defined(UTILS_H)
#define UTILS_H


#define ARRAY_LEN(_arr) ((int)sizeof(_arr) / (int)sizeof(*_arr))
#define UNUSED(x) (void)(x)
#define RANDFLOAT ((float)rand()/(float)(RAND_MAX))
#define RANDRANGE(low,hi) (RANDFLOAT*(hi-low) + low)

#define MAX(a,b) (a > b ? a : b)

void Fatal(const char *format, ...);
float GetTime(void);
void PrintFps(void);


void GLCheck(const char* name);

#endif /* UTILS_H */
