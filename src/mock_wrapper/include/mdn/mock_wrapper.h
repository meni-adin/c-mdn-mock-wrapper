#ifndef MDN_MOCK_WRAPPER_H
#define MDN_MOCK_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

void *mdn_MW_malloc_(const char *callerName, size_t size);
#ifdef MDN_MW_ENABLE_MOCKING
# define MDN_MW_malloc(size) mdn_MW_malloc_(__func__, (size))
#else
# define MDN_MW_malloc(size) malloc(size)
#endif  // MDN_MW_ENABLE_MOCKING

void *mdn_MW_realloc_(const char *callerName, void *ptr, size_t size);
#ifdef MDN_MW_ENABLE_MOCKING
# define MDN_MW_realloc(ptr, size) mdn_MW_realloc_(__func__, (ptr), (size))
#else
# define MDN_MW_realloc(ptr, size) realloc((ptr), (size))
#endif  // MDN_MW_ENABLE_MOCKING

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // MDN_MOCK_WRAPPER_H
