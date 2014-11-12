#ifndef HASH_H
#define HASH_H

int getHashedKey( char* key ){
	int i = 0;
	int hash = 0;
	char x = key[ 0 ];
	while( x != '\0' ){
		hash += key[ i ];
		i++;
		x = key[ i ];
	}
	return hash;
}

#endif
