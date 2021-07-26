#include <stdio.h>
#include <sys/stat.h>
   #include <sys/types.h>
   #include <unistd.h>

void modify_if_public_writable(char* pathname);

int main (int argc, char* argv[]) {
    
    for (int i=1; i<argc; ++i) {
    
        modify_if_public_writable(argv[i]);
        
    }
    
    return 0;
}

void modify_if_public_writable(char* pathname) {
// call stat inside of here to get the original permissions
    struct stat sb;
    if (stat(pathname, &sb) == -1) {
        perror("failed to get stat for file");
        return;
    }
    // check not already "not publically writeable"
    if (!(sb.st_mode & S_IWOTH)) {
        printf("%s is not publically writable", pathname);
        return;
    }
    
    printf("removing public write from %s", pathname);
    // modify the mode to get new permissions
    mode_t new_mode = sb.st_mode & ~S_IWOTH;

    // use chmod to set the permissions
    if (chmod(pathname, new_mode) == -1) {
        perror("chmod failed to complete");
    }
    

}