# Projet Client-Serveur en C (TCP & UDP)

## 📖 Description
Ce projet implémente des clients et serveurs en **C** utilisant les protocoles **TCP** et **UDP**.  
- Le **serveur TCP** envoie un message de bienvenue et communique avec le client.  
- Le **client TCP** envoie et reçoit des messages via une connexion persistante.  
- Le **serveur UDP** attend un message d’un client et l'affiche.  
- Le **client UDP** envoie l’heure actuelle au serveur.

## 📂 Fichiers
| Fichier        | Description |
|---------------|------------|
| `TcpServer.c` | Serveur TCP, écoute les connexions et communique avec les clients. |
| `TcpClient.c` | Client TCP, se connecte au serveur et échange des messages. |
| `UdpServer.c` | Serveur UDP, reçoit un message du client et l'affiche. |
| `UdpClient.c` | Client UDP, envoie l’heure actuelle au serveur. |
| `Makefile`    | Script pour compiler et exécuter les programmes facilement. |

---

## 🛠️ **Compilation**
Utilise le **Makefile** pour compiler tous les fichiers :
```bash
make all  # Pour tout compiler 

make run_tcp_server  # Pour exécuter le serveur TCP
make run_tcp_client  # Pour exécuter le client TCP
make run_udp_server  # Pour exécuter le serveur UDP
make run_udp_client  # Pour exécuter le client UDP
```

## 📝 **Notes**
- Assurez-vous que les ports utilisés (par défaut 8080) sont disponibles et non bloqués par un pare-feu.
- Le client TCP et le client UDP nécessitent l'adresse du serveur comme argument lors de l'exécution.