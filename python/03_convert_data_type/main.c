// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-
#include <stdio.h>
#include <stdlib.h>

int write_data (void)
{
  FILE* fp;

  //data to write
  int num = 900;
  double d = 7.85;
  char str[] = "abc";

  //open file
  fp = fopen( "test.bin", "wb" );
  if( fp == NULL ){
    fputs( "ファイルオープンに失敗しました。\n", stderr );
    exit( EXIT_FAILURE );
  }

  //write data in binary
  //fwrite( &data, sizeof(data[0]), sizeof(str)/sizeof(data[0]), file_name );
  fwrite( &num, sizeof(num), 1, fp );
  fwrite( &d, sizeof(d), 1, fp );
  fwrite( str, sizeof(str[0]), sizeof(str), fp );
  //close
  if( fclose( fp ) == EOF ){
    fputs( "ファイルクローズに失敗しました。\n", stderr );
    exit( EXIT_FAILURE );
  }
  return 0;
}

int read_data(){
  FILE* fp;
  int num;
  double d;
  char str2[7]="";
  fp = fopen( "test.bin", "rb" );
  if( fp == NULL ){
    fputs( "ファイルオープンに失敗しました。\n", stderr );
    exit( EXIT_FAILURE );
  }
  fread( &num, sizeof(num), 1, fp );
  fread( &d, sizeof(d), 1, fp );
  fread( str2, sizeof(char), sizeof(str2), fp );
  printf( "\nreading file ...\n\n");
  printf( "%d\n", num );
  printf( "%f\n", d );
  printf( "%s\n", str2 );
  if( fclose( fp ) == EOF ){
    fputs( "ファイルクローズに失敗しました。\n", stderr );
    exit( EXIT_FAILURE );
  }
  return 0;
}

int main(void)
{
  write_data();
  read_data();
  return 0;
}

