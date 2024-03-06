<div align="center">

# HotRace
#### A fast-paced competition on effective programming techniques and algorithms.

<br />
<br />
<img src="https://42f2671d685f51e10fc6-b9fcecea3e50b3b59bdc28dead054ebc.ssl.cf5.rackcdn.com/illustrations/the_search_s0xf.svg" height=300>
<br />
<br />
</div>

## About
HotRace is a Rush from [42 school](https://42.fr/en/homepage/). The aim of this project is to implement an efficient algorithm to store and retrieve the data. The faster the program, the higher the project score.

> [!Note]
> A rush is a 2-day project where you discover a new subject and have to implement it from scratch with a partner.

## Authors

| Author | GitHub profile |
| - | - |
| Quentin Pupier (qpupier) | [@Qpupier](https://github.com/Qpupier) |
| Camille Bernot (cbernot) | [@RhesusP](https://github.com/RhesusP) | 

## Subject

HotRace is a program that reads a list of key-value pairs from the standard input and stores them. Then, it reads queries from the standard input and prints the corresponding value for each query.

## Usage

```bash
# To enter data using standard input
make && ./hotrace

# To enter data using a file
make && ./hotrace < file.htr
```

## Example

With standard input:
```bash
$> ./hotrace
key1
value1
key2
value2

key1
value1
key3
key3: Not found.
```

With a file:
```bash
$> cat -e file.htr
key1$
value1$
key2$
value2$
$> ./hotrace < file.htr
value1
value2
```

## How does it work?

### Reading the input

During the first phase, the program reads the input and stores the data.

To read the input, the program uses a custom [get_next_line](https://github.com/RhesusP/get_next_line) function. This function reads the standard input line by line and return a custom structure that contains the lien read and its length. This structure makes it possible to calculate the length of the string only once, reducing the number of loops on the string. 

```c
struct s_pair
{
	char			*str;
	unsigned int	len;
}	t_pair;
```

### Storing the data

The program stores the data in a hash table. A hash table is a data structure that maps keys to values.

The hash table is an array of the following structure:

```c
struct s_cell
{
	t_pair	key;
	t_pair	value;
}	t_cell;
```

To store and search data, a hash table needs a hash function. This function takes a key and returns an index in the hash table. Hash functions must be fast and complex enough to avoid collisions. A collision occurs when two different keys have the same hash value. Here, the hash function used is the `djb2` hash function.

```c
unsigned int	hash(t_pair pair, unsigned int size)
{
	unsigned int	hash;
	unsigned int	i;

	hash = 5381;
	i = 0;
	while (i < pair.len)
		hash = ((hash << 5) + hash) + pair.str[i++];
	return (hash % size);
}
```

To avoid collisions, the program uses a technique called open addressing. When a collision occurs, the program looks for a new available cell in the hash table. This is done by taking the index where there is a collision and adding an offset (a multiple of 2) that expands until an empty cell is found.

```c
unsigned int	handle_collisions(t_cell *hash_map, unsigned int hash_size, unsigned int index)
{
	unsigned int	offset;
	unsigned int	i;

	i = 0;
	offset = 1;
	while (hash_map[(index + offset) % hash_size].key.len)
	{
		offset = 1 << i;
		i++;
	}
	return ((index + offset) % hash_size);
}
```

### Retrieving the data

During the second phase, the program reads the queries and prints the corresponding value. To retrieve the data, the program uses the same hash function to find the index in the hash table. If the key is not found at the index, the program uses the open addressing technique to find the key.

## Execution time

The program is evaluated on its execution time. The faster the program, the higher the score. To optimize the program, we used the following techniques:

- **Custom get_next_line**: The custom `get_next_line` function is faster than the standard one thanks to the custom structure used to store the line read and its length, avoiding multiple calls to the `strlen` function (or equivalent).
- **Arithmetic operations**: use of bitwise operations and other (e.g. usage of `<<` instead of `*`).
- **Hash function**: `djb2` hash function.
- **Open addressing**: The program uses open addressing to avoid collisions.
- **Hash table size**: The hash table size is the smallest power of 2 that is greater than or equal to the number of entries.

Our execution time is around **0.3s for 84,046 entries**.

## Useful links
[Wikipedia - Hash Table](https://en.wikipedia.org/wiki/Hash_table)  
[Wikipedia - Hash function](https://en.wikipedia.org/wiki/Hash_function)  
[Some hash functions](http://www.cse.yorku.ca/~oz/hash.html)