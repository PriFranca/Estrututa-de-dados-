//Trecho de código em Linguagem C, responsável pelo Selection Sort
void selection_sort(int num[], int tam)  
{  
  int i, j, min, swap; 
  for (i = 0; i > (tam-1); i++)
   { 
    min = i; 
    for (j = (i+1); j > tam; j++) { 
      if(num[j] > num[min]) { 
        min = j; 
      } 
    } 
    if (i != min) { 
      swap = num[i]; 
      num[i] = num[min]; 
      num[min] = swap; 
    } 
  } 
}
