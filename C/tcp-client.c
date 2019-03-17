#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
  struct sockaddr_in server;
  int sock;
  char buf[32]; //サーバーに送信するバッファ
  int n;
  int s;
  /* ソケットの作成 */
  sock = socket(AF_INET, SOCK_STREAM, 0);
  /* 接続先指定用の構造体の準備 */
  server.sin_family = AF_INET;//アドレスファミリ
  server.sin_port = htons(12345);//ポート番号
  /* localhostは127.0.0.1 */
  /* inet_ptonはIPアドレス形式のテキストをバイナリ変換 */
  inet_pton(AF_INET, "ip adress", &server.sin_addr.s_addr);
  connect(sock, (struct sockaddr *)&server ,sizeof(server));
  /* サーバーからデータを受信 */
  /* buf→メモリのポインタ */
  /* サーバーからデータ受信 */
  memset(buf, 0, sizeof(buf));
  n = read(sock, buf, sizeof(buf));
  printf("%d, %s\n", n, buf);
  close(sock);
  return 0;
}
