#pragma once

#ifdef __linux__ 

#include <tiny_websockets/internals/ws_common.hpp>
#include <tiny_websockets/network/tcp_server.hpp>
#include <tiny_websockets/network/linux/linux_tcp_client.hpp>

#define DEFAULT_BACKLOG_SIZE 5

namespace websockets { namespace network {
	class LinuxTcpServer : public TcpServer {
    public:
        LinuxTcpServer(size_t backlog = DEFAULT_BACKLOG_SIZE) : _num_backlog(backlog) {}
        bool listen(WSString host, int port) override;
		TcpClient* accept() override;
        bool available() override;
        void close() override;
        virtual ~LinuxTcpServer();
    private:
        int _socket;
        size_t _num_backlog;
    };
}} // websockets::network

#endif // #ifdef __linux__ 