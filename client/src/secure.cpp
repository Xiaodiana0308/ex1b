#include"./../inc/Secure.h"

int secure_enc(class input_client *clie)//加密压缩函数[上传用]
{
    char fullpath[700];
    //openssl enc -e -aes256 -k wxq -pbkdf2 -in text.csv -out back.csv
    sprintf(fullpath,"cd %s && openssl enc -e -aes256 -k %s -pbkdf2 -in %s -out aes256_%s",clie->send_filepath,clie->password,clie->send_filename,clie->send_filename);
    // printf("1=%s\n",fullpath);
    //生成文件：filename  ->   aes256_filename
    int ssl;
    if((ssl=system(fullpath))!=0){
        perror("system");
        return -1;
    }
    memset(&(*clie).send_full,'\0',strlen((*clie).send_full));
    sprintf((*clie).send_full,"%saes256_%s",(*clie).send_filepath,(*clie).send_filename);//修改全路径到新生成的压缩文件下
    return 0;
    //上传时变了总路径，其他没变
}

int secure_del(class input_client *clie)//删除压缩文件[上传用]
{
    char fullpath[700];
    sprintf(fullpath,"cd %s && rm -rf aes256_%s",clie->send_filepath,clie->send_filename);
    // printf("2=%s\n",fullpath);
    int ssl;
    if((ssl=system(fullpath))!=0){
        perror("system");
        return -1;
    }
    return 0;
}

int secure_est(class input_client *clie)//修改接收的文件名，创建未解密的预文件[下载用]
{
    memset(&(*clie).send_full,'\0',strlen((*clie).send_full));
    sprintf((*clie).send_full,"%saes256_%s",(*clie).send_filepath,(*clie).send_filename);//修改全路径到新生成的压缩文件下
    // printf("3=%s\n",(clie)->send_full);
    return 0;
    //下载时变了总路径，其他的没变
}


int secure_dec(class input_client *clie)//解密解压缩函数[下载用]
{
    //临时文件解压缩
    char fullpath[700]={0};
    //openssl enc -d -aes256 -k wxq -pbkdf2 -in text.csv -out text.csv
    sprintf(fullpath,"cd %s && openssl enc -d -aes256 -k %s -pbkdf2 -in aes256_%s -out %s",clie->send_filepath,clie->password,clie->send_filename,clie->send_filename);
    // printf("4=%s\n",fullpath);
    //生成文件：aes256_filename  ->   filename
    int ssl;
    if((ssl=system(fullpath))!=0){
        perror("system");
        // return -1;
    }
    //删除临时文件
    char fullpath1[700]={0};
    sprintf(fullpath1,"cd %s && rm -rf aes256_%s",clie->send_filepath,clie->send_filename);
    if((ssl=system(fullpath1))!=0){
        perror("system");
        return -1;
    }
    // printf("5=%s\n",fullpath1);
    return 0;
}
