#ifndef MDN_MOCK_WRAPPER_H
#define MDN_MOCK_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

void *mdn_mw_malloc(const char *callerName, size_t size);
#ifdef MW_ENABLE_MOCKING
# define MW_malloc(size) mw_malloc(__func__, (size))
#else
# define MW_malloc(size) malloc(size)
#endif  // ENABLE_MOCKING

void *mw_realloc(const char *callerName, void *ptr, size_t size);
#ifdef MW_ENABLE_MOCKING
# define MW_realloc(ptr, size) mw_realloc(__func__, (ptr), (size))
#else
# define MW_realloc(ptr, size) realloc((ptr), (size))
#endif  // ENABLE_MOCKING

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // MDN_MOCK_WRAPPER_H
