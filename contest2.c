#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct struct_dummy {
  char nc;
  struct struct_dummy *next;
} Seq;

int chkCdn(char sq[], char *cdn);

Seq *srchS(Seq *sq,char *startcdn);

Seq *srchE(Seq *sq,char *stopcdn[3]);

int freeLISTnodes(Seq *sq);

int  main(int argc, char *argv[]){

  char mrna[]="";

  char startcdn[]="AUG";

  char *stopcdn[3] ={"UAA","UAG","UGA"};

  Seq *sq1;
  Seq *sq2;
  Seq *sq2stop;
  Seq *sq2end;
  Seq *pt;

  int numfound;
  int nth=0;

  numfound = chkCdn(mrna,startcdn);

  printf("%d\n",numfound);
  
sq1 = (Seq *)malloc(sizeof(Seq));

  pt= sq1;

  for(nth=0;nth<strlen(mrna)-1;nth=nth+1){
    pt->nc=mrna[nth];
    pt->next= (Seq *)malloc(sizeof(Seq));
    pt=pt->next;
  }

  pt->nc=mrna[nth];

  pt->next=NULL;

  for(pt=sq1;pt!=NULL;pt=pt->next){
    printf("%c",pt->nc);
  }

  printf("\n");
  
  sq2=srchS(sq1,startcdn);
  
   if(sq2==NULL){
    printf("Start: Not found\n");
  } else{
    sq2stop=srchE(sq2,stopcdn);
    if(sq2stop==NULL){
      printf("Stop: Not found\n");
    } else {


sq2end=sq2stop->next->next->next;

for(pt=sq2;pt!=sq2end;pt=pt->next){

printf("%c",pt->nc);
}
printf("\n");
}
}
   freeLISTnodes(sq1);
 return 0;
}

int chkCdn(char sq[],char *cdn){

  char* str;
  int count=0,i,n;
  
  char A,U,G;
  A=(*cdn);
  U=*(cdn+1);
  G=*(cdn+2);
  
  n=strlen(sq);

    for(i=0;i<n;i++){
      if(sq[i]=='A'){
	if(sq[i+1]=='U'){
	  if(sq[i+2]=='G'){
	    count++;
	  }
	}
      }
    }
    return count;
}

Seq *srchS(Seq *sq,char *startcdn){

  Seq* sump;
  Seq* pt;

  for(pt=sq;pt!=NULL;pt=pt->next){
     if(pt->next==NULL){
      return NULL;
    }
    if(pt->nc==*startcdn){
      if(pt->next->nc==*(startcdn+1)){
	if(pt->next->next->nc==*(startcdn+2)){
	      sump=pt;
	      break;
	    }
      }
    }
   
  } 
  return sump;
  }

Seq *srchE(Seq *sq,char *stopcdn[3]){

  Seq* sump;
  Seq* pt;

  for(pt=sq;pt!=NULL;pt=pt->next->next->next){
     if(pt->next->next->next==NULL){
      return NULL;
    }
    if(pt->nc==*stopcdn[0]){
      if(pt->next->nc==*(stopcdn[0]+1)){
	if(pt->next->next->nc==*(stopcdn[0]+2)){
	  sump=pt;
	  break;
	}
      }
    }
    if(pt->nc==*stopcdn[1]){
       if(pt->next->next->next==NULL){
      return NULL;
    }
      if(pt->next->nc==*(stopcdn[1]+1)){
	if(pt->next->next->nc==*(stopcdn[1]+2)){
	  sump=pt;
	  break;
	}
      }
    }
    if(pt->nc==*stopcdn[2]){
       if(pt->next->next->next==NULL){
      return NULL;
    }
      if(pt->next->nc==*(stopcdn[2]+1)){
	if(pt->next->next->nc==*(stopcdn[2]+2)){
	  sump=pt;
	  break;
	}
      }
    }
  }
  return sump;
}

int freeLISTnodes(Seq *sq){

  Seq* pt;

  for(pt=sq;sq!=NULL;sq=sq->next){
    if(pt->next==NULL){
      free(pt);
      pt=sq;
    }
  }

  return 0;
}
  
      


    
