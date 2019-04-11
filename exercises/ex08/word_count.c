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

static void print_table(gpointer key, gpointer value)
{
    printf("Key: %s, Value: %i\n", *key, *value);
}



int main(int argc, char** argv) {
    char buf[1000];
    // read_file("text.txt");

    GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);
    int table_size = 0;

    FILE *ptr_file;
    char delim[] = " ";


		ptr_file =fopen("text.txt", "r");
		if (!ptr_file){
      printf("Could not read file name.");
      return 1;
    }

    while (fgets(buf,1000, ptr_file)!=NULL) {
        printf("%s\n",buf);
        char *ptr = strtok(buf, delim);
        if(!ptr) continue;

      	while(ptr != NULL) {
          // splitting text line into words by spaces
      		printf("'%s'\n", ptr);
      		ptr = strtok(NULL, delim);

          if (!ptr) continue;

          gpointer key = ptr;
          gpointer val;

          char *old_key;
          int *old_value;

          /* Try looking up this key. */
          if (g_hash_table_lookup_extended (hash, key, &old_key, &old_value)) {
              /* Insert the new value */
              g_hash_table_insert (hash, g_strdup (key), *old_value+1);
              /* Just free the key and value */
              g_free (old_key);
              g_free (old_value);
          }
          else
          {
              /* Insert into our hash table it is not a duplicate. */
              g_hash_table_insert (hash, g_strdup (key), 0);
              table_size ++;
          }
        }
    }

    int total = 0;

    // Print the results
    g_hash_table_foreach(hash, print_table, &total);
		fclose(ptr_file);

    return 0;
}
