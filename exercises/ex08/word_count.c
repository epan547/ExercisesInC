/* Making a word count histogram of a given text file, using Glib.

From http://www.ibm.com/developerworks/linux/tutorials/l-glib/
gcc 'pkg‑config ‑‑cflags ‑‑libs glib‑2.0' ‑o words word_count.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

// int read_file(char* filename){
// 		FILE *ptr_file;
// 		int x;
//
// 		ptr_file =fopen(filename, "r");
//     fprintf("%s",filename);
// 		if (!ptr_file)
// 			return 1;
//
// 		for (x=1; x<=10; x++)
// 			fprintf(ptr_file,"%d\n", x);
//
// 		fclose(ptr_file);
//
// 		return  0;
// }

int main(int argc, char** argv) {
    GList* list = NULL;
    char buf[1000];
    list = g_list_append(list, "Hello world!");
    printf("The first item is '%s'\n", (char *) g_list_first(list)->data);
    // read_file("text.txt");

    GHashTable∗ hash = g_hash_table_new(g_str_hash, g_str_equal);

    FILE *ptr_file;
    char delim[] = " ";


		ptr_file =fopen("text.txt", "r");
		if (!ptr_file){
      printf("Could not read file name.");
      return 1;
    }

    while (fgets(buf,1000, ptr_file)!=NULL) {
        printf("%s",buf);
        char *ptr = strtok(buf, delim);

      	while(ptr != NULL) {
      		printf("'%s'\n", ptr);
      		ptr = strtok(NULL, delim);

          char∗∗ key_ptr = &state;
          char∗∗ value_ptr = &capital;
          gboolean result = g_hash_table_lookup_extended(hash, buf, (gpointer∗)key_ptr, (gpointer∗)value_ptr);

          if(gboolean == true){
            g_hash_table_insert(hash, key_ptr, &(*value_ptr+1));
          }
          else{
            g_hash_table_insert(hash, &buf, &0);
          }
        }
    }


		fclose(ptr_file);

    return 0;
}
