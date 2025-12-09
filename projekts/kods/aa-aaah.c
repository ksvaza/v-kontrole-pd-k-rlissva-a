#include <stdio.h>

int main() {
    const char* teksts = "Kad skolēni sabojā git projektu: Nu ko… laiks jaunam klonam.";
    void* ptr = (void*)teksts;
    long long count = 0;
    while (*(char*)ptr != '\0') {
        if (*(char*)ptr == 'a') {
            count++;
        }
        ptr = (char*)ptr + 1;
    }
    printf("%lld\n", count);
    return 0;
}