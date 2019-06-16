# Text-compressor-using-huffman-codes
This source code implements the huffman algorithm to perform the compression of a plain text file. for this a file is generated which contains the probabilities of each of the symbols defined in the symbols dictionary.


To execute this algorithm correctly, you must first compile the code in c that generates the probability of the symbols set in it.


As a second step you must execute the source code corresponding to the Huffman encoder. The execution of this will generate a .dat file which is the compressed text file. Note: When performing the Hamming algorithm and to achieve a considerable reduction in the size of the text file, the writing of the .dat file is done directly to disk using a writing strategy that allows to write byte by byte the data.

Finally, to recover the text file, execute the corresponding source code for the decoder.

