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
  /* 接続先のIPアドレスや、ポート番号を指定できる構造体で,bindシステムコールでsockaddr_in構造体のデータと関連づけられる。 */
  struct sockaddr_in addr;
  struct sockaddr_in client;
  int len;
  int sock;
  /* ファイルディスクリプタ値が返る */
  /* socket(,protocol) protocol
  -> sudo cat ./etc/protocols */
  sock0 = socket(AF_INET, SOCK_STREAM, 0);
  printf("%i\n",sock0);
  addr.sin_family = AF_INET;
  addr.sin_port = htons(12345);
  addr.sin_addr.s_addr = INADDR_ANY;
  /* 設定終了 */
  /* ソケットへ命名 */
  bind(sock0, (struct sockaddr*)&addr, sizeof(addr));
  /* 接続を待ち受ける */
  listen(sock0,5);
  len = sizeof(client);
  sock = accept(sock0, (struct sockaddr*)&client, &len);
  /* 5文字送信 */
  /* クライアントからきたsocketの情報を書き込む */
  write(sock,"Hello",5);
  /* TCPセッションの終了 */
  close(sock);
  /* listenするsocketの終了 */
  close(sock0);
  return 0;
}
