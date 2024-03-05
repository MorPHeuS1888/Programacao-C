#include <stdio.h>

int main(){
    int d, l, o;
    char c;

    c = '3';

    switch(c) {
    case 'a':
    case 'e':
    case 'i':
      l++;
       break;
    case '1': case '2' :
        ++d;
       break;
    case '3':
        d++;
    default:
       o++;
    }

    c = 'a';

    switch(c) {
    case 'a':
    case 'e':
    case 'i':
      l++;
       break;
    case '1': case '2' :
        ++d;
       break;
    case '3':
        d++;
    default:
       o++;
    }

    c = 'x';

    switch(c) {
    case 'a':
    case 'e':
    case 'i':
      l++;
       break;
    case '1': case '2' :
        ++d;
       break;
    case '3':
        d++;
    default:
       o++;
    }

    c = 'e';

    switch(c) {
    case 'a':
    case 'e':
    case 'i':
      l++;
       break;
    case '1': case '2' :
        ++d;
       break;
    case '3':
        d++;
    default:
       o++;
    }

        c = '1';

    switch(c) {
    case 'a':
    case 'e':
    case 'i':
      l++;
       break;
    case '1': case '2' :
        ++d;
       break;
    case '3':
        d++;
    default:
       o++;
    }

    printf("%d %d %d ",d,l,o);

    return 0;
}