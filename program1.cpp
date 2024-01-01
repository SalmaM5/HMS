
int main(int argc, char** argv){
    
   int rank,size;
   int ARRINT[MAXsize];
   double ARRD[MAXsize],T1,T2,TP0,TP1; 
   char ARRC[MAXsize];
   MPI_Init(NULL,NULL);
   MPI_Comm_rank(MPI_COMM_WORLD,&rank);
   MPI_Comm_size(MPI_COMM_WORLD,&size); 
   
    for(int i =0 ; i<MAXsize;i++){
       ARRINT[i]=i;
       }
    for(int i =0 ; i<MAXsize;i++){
        ARRD[i]=1.2;
    }
    for(int i=0;i<MAXsize;i++){
        ARRC[i]='a';
    }
    
 if(rank==0){
  T1=MPI_Wtime();
  MPI_Send(ARRINT,1000,MPI_INT,1,123,MPI_COMM_WORLD);
  //MPI_Send(ARRD,1000,MPI_DOUBLE,1,123,MPI_COMM_WORLD);
  //MPI_Send(ARRC,1000,MPI_CHAR,1,123,MPI_COMM_WORLD);
  TP0=T2-T1;
  MPI_Recv(&TP1,1,MPI_INT,0,123,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
  cout<<"TP0 =" <<TP0;
  cout<<"TP1 =" <<TP1;
 }
 
 else{
     
     T1=MPI_Wtime();
     MPI_Recv(ARRINT,1000,MPI_INT,0,123,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
     //MPI_Recv(ARRD,1000,MPI_DOUBLE,0,123,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
     //MPI_Recv(ARRC,1000,MPI_DOUBLE,0,123,MPI_COMM_WORLD,MPI_STATUS_IGNORE);;
     T2=MPI_Wtime();
     TP1=T2-T1;
     MPI_Send(&TP1,1,MPI_INT,0,123,MPI_COMM_WORLD);
 }
    
    
    
    
 
 
 
 
 MPI_Finalize();   
    
    
    
    
}
