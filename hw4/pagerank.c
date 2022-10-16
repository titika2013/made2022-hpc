// Реализация pagerank на заданном графе

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    float d = 0.85;

    char filename[] = "graph.txt";
    FILE *fp;
    if((fp = fopen(filename,"r")) == NULL) {
        fprintf(stderr,"[Error] Cannot open the file");
        exit(1);
    }

    int n=8;
    char ch;
    char str[100];
    ch = getc(fp);
    ungetc(ch, fp);

    float **a = malloc(sizeof *a * n);
	int i, j, node1, node2;
	
	for (i = 0; i < n; i++) {
	  	a[i] = malloc(sizeof *a[i] * n);
	}

	for(i = 0; i < n; i++){ 
        for(j = 0; j < n; j++){ 
        	a[i][j] = 0.0;
        }
    }

	while(!feof(fp)){
	    fscanf(fp,"%d%d", &node1, &node2);
	    a[node1][node2] = 1.0;
	}
    
    float **at = malloc(sizeof *at * n);

	for (i = 0; i < n; i++) {
	    at[i] = malloc(sizeof *at[i] * n);
	}

	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			at[i][j] = 0.0;
		}
	}

	float p[n];
	
	for(i=0; i<n; i++) {
		p[i] = 1.0 / n;
	}

	int out_link[n];

	for (i=0; i<n; i++) {
		out_link[i] = 0;
	}

	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			if (a[i][j] != 0.0) {
				out_link[i] = out_link[i] + 1;
			}
		}
	}

	for (i=0; i<n; i++){
		if (out_link[i] == 0){
			for (j=0; j<n; j++){
				a[i][j] = 1.0 / n;
			}
		} else {
			for (j=0; j<n; j++){
				if (a[i][j] != 0) {
					a[i][j] = a[i][j] / out_link[i];
				}
			}
		}
	}

	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			at[j][i] = a[i][j];
		}
	}

	int looping = 1;
	int k = 0;
	float p_new[n];

	while (looping) {
		for (i=0; i<n; i++){
			p_new[i] = 0.0;
		}
		
		for (i=0; i<n; i++){
			for (j=0; j<n; j++){
				p_new[i] = p_new[i] + (at[i][j] * p[j]);
			}
		} 

		for(i=0; i<n; i++){
		 	p_new[i] = d * p_new[i] + (1.0 - d) / n;
		}

	    float error = 0.0;
	    for(i=0; i<n; i++){
	        error =  error + fabs(p_new[i] - p[i]);
	    }

	    if (error < 0.000001){
	        looping = 0;
	    }

	    for (i=0; i<n;i++){
	    	p[i] = p_new[i];
		}

	    k = k + 1;
	}

	printf ("Final Pagerank results:\n\n");
	for (i=0; i<n; i++){
		printf("%f ", p[i]);
		if(i!=(n-1)){ printf(", "); }
	}

	return 0;
}