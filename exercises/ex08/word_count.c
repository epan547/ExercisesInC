/* Making a word count histogram of a given text file, using Glib.

From http://www.ibm.com/developerworks/linux/tutorials/l-glib/
gcc 'pkg‑config ‑‑cflags ‑‑libs glib‑2.0' ‑o words word_count.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

void print_table(gpointer key, gpointer value)
{
    printf("Key: %s, Value: %i\n", (gchar*)key, (gint)value);
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

    // Separate the words in the file
    while (fgets(buf,1000, ptr_file)!=NULL) {
        // printf("%s\n",buf);
        char *ptr = strtok(buf, delim);
        if(!ptr) continue;

      	while(ptr != NULL) {
          // splitting text line into words by spaces
      		printf("'%s'\n", ptr);
      		ptr = strtok(NULL, delim);

          if (!ptr) continue;

          gchar* key = g_strdup(ptr);
          gint val = 1;

          int value = (int) g_hash_table_lookup(hash, key);
          // printf("%i\n", value);
          if(value == 0){
            g_hash_table_insert(hash, g_strdup(key),GINT_TO_POINTER(1));
          }
          else{
            g_hash_table_insert(hash, g_strdup(key),GINT_TO_POINTER(value+1));
          }

          g_hash_table_foreach(hash, (GHFunc)print_table, key); // key is just a placeholder
        }
    }

    // char* fake = "hi";
    // Print the results
    // g_hash_table_foreach(hash, print_table, &fake);
		fclose(ptr_file);

    return 0;
}
