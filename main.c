#include <stdio.h>
#include <stdlib.h>


#include "generator.h"

int main() {
  // somthing
  char *publicKey;
  char *privateKey;
  GeneratePublicPrivateKey(&publicKey, &privateKey);


  printf("public :%s\n", publicKey);
  printf("private :%s\n", privateKey);
}
