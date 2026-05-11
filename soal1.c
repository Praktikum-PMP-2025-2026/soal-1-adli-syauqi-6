/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : Foundation of Algorithm
 *   Hari dan Tanggal    : 11 Mei 2026
 *   Nama (NIM)          : Muhammad Adli Syauqi (13224082)
 *   Nama File           : soal1.c
 *   Deskripsi           : Program memberikan graf dalam format adjacency matrix, kemudian mengembalikan degree setiap vertex, vertex dengan degree maksimum, dan vertex yang isolated
 *  
 */


#include <stdio.h>

#define MAX 100

typedef struct{
    int size;
    int data[MAX][MAX];
} Graph;

int main(){
    int n;
    scanf("%d", &n);

    Graph graph;
    graph.size = n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &graph.data[i][j]);
            // printf("%d ", graph.data[i][j]);
        }
    }

    int degree = 0;
    int max_vertex_index = 0;
    int max_vertex_degree = 0;

    int isolated[n];
    int isolated_count = 0;



    for(int i = 0; i < n; i++){
        degree = 0;
        for(int j = 0; j < n; j++){
            
            if(graph.data[i][j] == 1){
                degree++;
            }
        }

        if(max_vertex_degree < degree){
            max_vertex_index = i;
            max_vertex_degree = degree;
        }

        if(degree == 0){
            isolated[isolated_count] = i;
            isolated_count++;
        }

        printf("DEGREE %d %d\n", i, degree);
    }

    printf("MAX_VERTEX %d\n", max_vertex_index);


    if(isolated_count == 0){
        printf("ISOLATED NONE");
    } else{
        printf("ISOLATED");
        for(int i = 0; i < isolated_count; i++){
            printf(" %d", isolated[i]);
        }
    }

}
