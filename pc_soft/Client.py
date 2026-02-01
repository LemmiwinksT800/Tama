import socket
import time
import recognition
import sys

HOST = '127.0.0.1'
PORT = 5000

def handle_client(conn):
    try:
        while True:
            data = conn.recv(1024)
            if not data:
                continue

            msg = data.decode().strip()
            print(f"Received: {msg}", flush=True)

            if msg == "PING!":
                conn.sendall(b"PONG!\n")

            elif msg == "EXIT":
                break
    finally:
        conn.close()

def main():
    com_port = sys.argv[1]

    stop_recognition = recognition.start_recognition(com_port)

    print("READY", flush=True)

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((HOST, PORT))
        s.listen(1)

        conn, addr = s.accept()
        print(f"Client connected: {addr}", flush=True)
        handle_client(conn)

    stop_recognition(wait_for_stop=False)

    while True:
        time.sleep(1)

if __name__ == "__main__":
    main()
