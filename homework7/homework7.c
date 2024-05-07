/******************************************************************
//
//  NAME:        Adam Graham
//
//  HOMEWORK:    7
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        March 25, 2024
//
//  FILE:        homework7.c
//
//  DESCRIPTION:
//   Reads binary data of a TCP header and generates a response header.
//
****************************************************************/

#include <stdio.h>

int readfile(const char[], unsigned char[]);
int writefile(const char[], const unsigned char[]);
void printheader(const unsigned char[]);
void makeheader(const unsigned char[], unsigned char[]);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Reads binary data of a TCP header and generates
//                 a response header.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : success
//
****************************************************************/

int main(int argc, char* argv[])
{
    unsigned char tcp_header[20];
    unsigned char response_header[20];

    if (readfile("request1.bin", tcp_header) == 0)
    {
        printf("***Success! Read request1.bin***\n");
        printheader(tcp_header);
        makeheader(tcp_header, response_header);
        if (writefile("response1.bin", response_header) == 0)
        {
            printf("***Success! Created response1 header***\n");
        }
        printheader(response_header);
    }
    printf("-----------------------------------------------------------\n\n");

    if (readfile("request2.bin", tcp_header) == 0)
    {
        printf("***Success! Read request2.bin***\n");
        printheader(tcp_header);
        makeheader(tcp_header, response_header);
        if (writefile("response2.bin", response_header) == 0)
        {
            printf("***Success! Created response2 header***\n");
        }
        printheader(response_header);
    }
    printf("-----------------------------------------------------------\n\n");

    if (readfile("request3.bin", tcp_header) == 0)
    {
        printf("***Success! Read request3.bin***\n");
        printheader(tcp_header);
        makeheader(tcp_header, response_header);
        if (writefile("response3.bin", response_header) == 0)
        {
            printf("***Success! Created response3 header***\n");
        }
        printheader(response_header);
    }
    printf("-----------------------------------------------------------\n\n");

    return 0;
}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   Reads data from a binary file and stores data into an
//                 unsigned char array.
//
//  Parameters:    filename (const char[]) : Filename to read from
//                 tcp_header (unsigned char[]) : An array to store the data
//
//  Return values:  0 : success
//                 -1 : error
//
****************************************************************/

int readfile(const char filename[], unsigned char tcp_header[])
{
    FILE *infile;
    int result;

    infile = fopen(filename, "rb");

    if (infile != NULL)
    {
        result = (fread(tcp_header, sizeof(unsigned char), 20, infile) == 20) ? 0 : -1;
        fclose(infile);
    }
    else
    {
        result = -1;
    }
    return result;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   Writes generated data to a new binary file.
//
//  Parameters:    filename (const char[]) : Filename to write to
//                 response_header (const unsigned char[]) : Response to write
//
//  Return values:  0 : success
//                 -1 : error
//
****************************************************************/

int writefile(const char filename[], const unsigned char response_header[])
{
    FILE *outfile;
    int result;

    outfile = fopen(filename, "wb");

    if (outfile != NULL)
    {
        result = (fwrite(response_header, sizeof(unsigned char), 20, outfile) == 20) ? 0 : -1;
        fclose(outfile);
    }
    else
    {
        result = -1;
    }
    return result;
}

/*****************************************************************
//
//  Function name: printheader
//
//  DESCRIPTION:   Displays a given header data in the specified form.
//
//  Parameters:    tcp_header (const unsigned char[]) : TCP header data to print.
//
//  Return values:  none
//
****************************************************************/

void printheader(const unsigned char tcp_header[])
{
    int source_port = (tcp_header[1] << 8) | tcp_header[0];
    int dest_port = (tcp_header[3] << 8) | tcp_header[2];
    unsigned int seq_number = (tcp_header[7] << 24) | (tcp_header[6] << 16) |
    (tcp_header[5] << 8) | tcp_header[4];
    unsigned int ack_number = (tcp_header[11] << 24) | (tcp_header[10] << 16) |
    (tcp_header[9] << 8) | tcp_header[8];
    int i;

    for (i = 0; i < 20; i++)
    {
        printf("%02X ", tcp_header[i]);
    }
    printf("\n");

    printf("Source port: %d\n", source_port);
    printf("Destination port: %d\n", dest_port);
    printf("Sequence number: %u\n", seq_number);
    printf("Acknowledgement number: %u\n", ack_number);

    printf("Control bits which are set to 1: \n");
    if ((tcp_header[13] & 0x01) >> 0)
    {
        printf("FIN\n");
    }
    if ((tcp_header[13] & 0x02) >> 1)
    {
        printf("SYN\n");
    }
    if ((tcp_header[13] & 0x04) >> 2)
    {
        printf("RST\n");
    }
    if ((tcp_header[13] & 0x08) >> 3)
    {
        printf("PSH\n");
    }
    if ((tcp_header[13] & 0x10) >> 4)
    {
        printf("ACK\n");
    }
    if ((tcp_header[13] & 0x20) >> 5)
    {
        printf("URG\n");
    }
    printf("\n");
}

/*****************************************************************
//
//  Function name: makeheader
//
//  DESCRIPTION:   Generates a response header based on a request header.
//
//  Parameters:    tcp_header (const unsigned char[]) : Request header that the response header is based on.
//                 response_header (unsigned char[]) : Array that stores the response header
//
//  Return values:  none
//
****************************************************************/

void makeheader(const unsigned char tcp_header[], unsigned char response_header[])
{
    int source_port = (tcp_header[1] << 8) | tcp_header[0];
    unsigned int seq_number = (tcp_header[7] << 24) | (tcp_header[6] << 16) |
    (tcp_header[5] << 8) | tcp_header[4];
    int i;

    /* Check if source port number is greater than 32767 (0x7FFF) */
    if ((source_port & 0x8000) != 0)
    {
        /* Flip the 4th and 11th bits */
        source_port ^= (1 << 5) | (1 << 12);
    }

    /* Switch the source and destination ports */
    response_header[0] = tcp_header[2];
    response_header[1] = tcp_header[3];
    response_header[2] = source_port & 0xFF;
    response_header[3] = (source_port >> 8) & 0xFF;

    /* Set acknowledgement number to the sequence number of the request header */
    response_header[8] = seq_number & 0xFF;
    response_header[9] = (seq_number >> 8) & 0xFF;
    response_header[10] = (seq_number >> 16) & 0xFF;
    response_header[11] = (seq_number >> 24) & 0xFF;

    /* Set the sequence number to the sequence number of the request header AND increment it */
    seq_number++;
    response_header[4] = seq_number & 0xFF;
    response_header[5] = (seq_number >> 8) & 0xFF;
    response_header[6] = (seq_number >> 16) & 0xFF;
    response_header[7] = (seq_number >> 24) & 0xFF;

    response_header[12] = tcp_header[12];

    if ((tcp_header[13] & 0x02) >> 1)
    {
        response_header[13] = tcp_header[13] | 0x12;
    }
    else
    {
        response_header[13] = tcp_header[13];
    }

    for (i = 14; i < 20; i++)
    {
        response_header[i] = tcp_header[i];
    }
}
