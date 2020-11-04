#define NADDR 100  /* The max size of the array that holds addresses */
#define LLENGTH 80

/* The name of the text file of the ip addresses */
#define TXT_INPUT "TXT_INPUT.txt"

/* The name of the binary file for dumping and reading the addresses */
#define BIN_FILE "BIN_FILE.bin"

typedef struct {
  int xx;
  int yy;
  int zz;
  int mm;
  char nickname[10];
} address_t;

/* read a single address_t from f */
address_t scan_address(FILE *f);

/* Use scan_address to read multiple addresses
 * from text file f to arr. Stop when you read in
 * a sentinel address
 */
void scan_addresses(address_t arr[], FILE *txt);

/* returns true if the address is 0.0.0.0 with an arbitrary name,
 * false otherwise
 */
int sentinel(address_t a);

/* Read an array of addresses in binary form from f to arr.
 * Stops after you encounter a sentinel.
 */
void read_addresses(address_t arr[], FILE *f);

/* write an array of addresses in binary form from arr to f
 * including the sentinel
 */
void write_addresses(address_t arr[], FILE *f);

/* print out a single address */
void print_address(address_t a);

/* compares two addresses */
int equal_address(address_t a1, address_t a2);
