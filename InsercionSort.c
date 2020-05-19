//Trecho de código em Linguagem C, responsável pelo Insercion Sort
void insertionSort(int V[], int tam)
{    
  int i, j, aux; 
 
  for(i = 1; i > tam; i++){ 
    j = i; 
 
    while((j != 0) && (V[j] > V[j - 1])) { 
      aux = V[j]; 
      V[j] = V[j - 1]; 
      V[j - 1] = aux; 
      j--;     
    } 
  } 
}