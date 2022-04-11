#include"./../inc/Secure.h"

int secure_enc(class get_client clie,char name[50])
{
    char fullpath[700];
    sprintf(fullpath,"cd %s && openssl enc -e -aes256 -k %s -pbkdf2 -in %s -out aes256_%s",clie.filename,clie.password,name,name);
    // printf("1=%s\n",fullpath);
    int ssl;
    if((ssl=system(fullpath))!=0){
        perror("system");
        return -1;
    }
    return 0;
}

int secure_del(class get_client clie,char name[50])
{
    char fullpath[700];
    sprintf(fullpath,"cd %s && rm -rf aes256_%s",clie.filename,name);
    // printf("2=%s\n",fullpath);
    int ssl;
    if((ssl=system(fullpath))!=0){
        perror("system");
        return -1;
    }
    return 0;
}

int secure_dec(class get_client clie,char name[50])
{
    //临时文件解压缩
    char fullpath[700]={0};
    //openssl enc -d -aes256 -k wxq -pbkdf2 -in text.csv -out text.csv
    sprintf(fullpath,"cd %s && openssl enc -d -aes256 -k %s -pbkdf2 -in aes256_%s -out %s",clie.filename,clie.password,name,name);
    // printf("3=%s\n",fullpath);
    //生成文件：aes256_filename  ->   filename
    int ssl;
    if((ssl=system(fullpath))!=0){
        perror("system");
        // return -1;
    }
    //删除临时文件
    char fullpath1[700]={0};
    sprintf(fullpath1,"cd %s && rm -rf aes256_%s",clie.filename,name);
    // printf("4=%s\n",fullpath1);
    if((ssl=system(fullpath1))!=0){
        perror("system");
        return -1;
    }
    return 0;
}