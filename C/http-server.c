/* https://corgi-lab.com/programming/c-lang/http-server-clang/ */
/* sockaddr_in構造体 http://www.fos.kuis.kyoto-u.ac.jp/le2soft/siryo-html/node16.html */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
  /* ソケット実装 */
  int sock0;
  /* ソケットの設定情報を保持させる構造体 */
  struct sockaddr_in addr;
  struct sockaddr_in client;
  int len;
  int sock;
  /* ファイルディスクリプタが返る */
  sock0 = socket(AF_INET,SOCK_STREAM,0);
  addr.sin_family = AF_INET;
  addr.sin_port = htons(12345);
  addr.sin_addr.s_addr = INADDR_ANY;
  /* 設定終了 */
  /* ソケットへ命名 */
  bind(sock0,(struct sockaddr*)&addr,sizeof(addr));
  /* 接続を待ち受ける */
  listen(sock0,5);
  len = sizeof(client);
  sock = accept(sock0,(struct sockaddr*)&client,&len);
  /* 5文字送信 */
  write(sock,"Hello",5);
  /* TCPセッションの終了 */
  close(sock);
  /* listenするsocketの終了 */
  close(sock0);
  return 0;
}
