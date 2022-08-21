
�#���y_X@R8"�L�_���_I2_�#u��_X@R8"�L�_���_I2_�#zwb|#�w%��<��ݢ>#�w%��<n�,��b����)��.��>#�w%��<������r�ߊܢ�.��>�#�w%��<��������.�+r�z'x.��>�#�w%��<������r�ܺ�ޝ̿���.��>�#�w%��<������r�ܺ�ޝ̿��.��>�#�w%��<�����������+������j.��>#�w%��<���������z.��>#�w%��<��-��>#�w%��<��ky�>��r��^���$z�i::r�ܺ�ޝ�::��\�w.���s;��r��^���$z�i::�����+�::��-��<r�ܺ�ޝ�>�����+�;��r��^���$z�i::���z<r�ܺ�ޝ�,�����+�>���z;�*^u��y�(rG��::���z<������::r�ߊ::r��>���z;�*rV���vW�:�������::��ݕ�{n�%��bu�^(r��y�b�_��ܢ){��::r��<<"��ݕ��jX�j�"<<��::zwe;�(r�->��_����()!"��i:��0�.{��W.r�"){r�->��_�֭�(������::��i::�֭�_r�^::�A 0�4);��n�wږ�;}��n�{k�;}�����i(r��y�b�_��ܢ){��::r��<<"��ݕ���"<<��::zwe;}����_���(r��y�b�_��ܢ,���_��ݕ�){��::r��<<"��ݕ��_���"<<��::zwe;}����_�yhi(r��y�b�_��ܢ,���{_��ݕ�){��::r��<<"��ݕ��_�yhi"<<��::zwe;}����_���(r��y�b�_��ܢ){��::r��<<"��ݕ��_���"<<��::zwe;}����_}��(r��y�b�_��ܢ){��::r��<<"��ݕ��_}��"<<��::zwe;}����_��,j(r��y�b�_��ܢ,��,j_���){��::r��<<"��ݕ��_��,j"<<��::zwe;}����_rZ,x(r��y�b�_��ܢ){��::r��<<"��ݕ��_rZ,x"<<��::zwe;}};*�
int main() {
    typedef websocketpp::message_buffer::message<websocketpp::message_buffer::alloc::con_msg_manager>
        message_type;
    typedef websocketpp::message_buffer::alloc::con_msg_manager<message_type>
        con_msg_man_type;

    con_msg_man_type::ptr manager = websocketpp::lib::make_shared<con_msg_man_type>();

    size_t foo = 1024;

    message_type::ptr input = manager->get_message(websocketpp::frame::opcode::TEXT,foo);
    message_type::ptr output = manager->get_message(websocketpp::frame::opcode::TEXT,foo);
    websocketpp::frame::masking_key_type key;

    std::random_device dev;



    key.i = 0x12345678;

    double m = 18094238402394.0824923;

    /*std::cout << "Some Math" << std::endl;
    {
        boost::timer::auto_cpu_timer t;

        for (int i = 0; i < foo; i++) {
            m /= 1.001;
        }

    }*/




	{
    std::cout << m << std::endl;

    std::cout << "Random Gen" << std::endl;
    {
        boost::timer::auto_cpu_timer t;

        input->get_raw_payload().replace(0,foo,foo,'\0');
        output->get_raw_payload().replace(0,foo,foo,'\0');
    }

    std::cout << "Out of place accelerated" << std::endl;
    {
        boost::timer::auto_cpu_timer t;

        websocketpp::frame::word_mask_exact(reinterpret_cast<uint8_t*>(const_cast<char*>(input->get_raw_payload().data())), reinterpret_cast<uint8_t*>(const_cast<char*>(output->get_raw_payload().data())), foo, key);
    }

    std::cout << websocketpp::utility::to_hex(input->get_payload().c_str(),20) << std::endl;
    std::cout << websocketpp::utility::to_hex(output->get_payload().c_str(),20) << std::endl;

    input->get_raw_payload().replace(0,foo,foo,'\0');
    output->get_raw_payload().replace(0,foo,foo,'\0');

    std::cout << "In place accelerated" << std::endl;
    {
        boost::timer::auto_cpu_timer t;

        websocketpp::frame::word_mask_exact(reinterpret_cast<uint8_t*>(const_cast<char*>(input->get_raw_payload().data())), reinterpret_cast<uint8_t*>(const_cast<char*>(input->get_raw_payload().data())), foo, key);
    }

    std::cout << websocketpp::utility::to_hex(input->get_payload().c_str(),20) << std::endl;
    // std::cout << websocketpp::utility::to_hex(output->get_payload().c_str(),20) << std::endl;

    input->get_raw_payload().replace(0,foo,foo,'\0');
    output->get_raw_payload().replace(0,foo,foo,'\0');
    std::cout << "Out of place byte by byte" << std::endl;
    {
        boost::timer::auto_cpu_timer t;

        websocketpp::frame::byte_mask(input->get_raw_payload().begin(), input->get_raw_payload().end(), output->get_raw_payload().begin(), key);
    }

    std::cout << websocketpp::utility::to_hex(input->get_payload().c_str(),20) << std::endl;
    std::cout << websocketpp::utility::to_hex(output->get_payload().c_str(),20) << std::endl;

    input->get_raw_payload().replace(0,foo,foo,'\0');
    output->get_raw_payload().replace(0,foo,foo,'\0');
    std::cout << "In place byte by byte" << std::endl;
    {
        boost::timer::auto_cpu_timer t;

        websocketpp::frame::byte_mask(input->get_raw_payload().begin(), input->get_raw_payload().end(), input->get_raw_payload().begin(), key);
    }

    std::cout << websocketpp::utility::to_hex(input->get_payload().c_str(),20) << std::endl;
    std::cout << websocketpp::utility::to_hex(output->get_payload().c_str(),20) << std::endl;

    input->get_raw_payload().replace(0,foo,foo,'a');
    output->get_raw_payload().replace(0,foo,foo,'b');
    std::cout << "Copy" << std::endl;
    {
        boost::timer::auto_cpu_timer t;

        std::copy(input->get_raw_payload().begin(), input->get_raw_payload().end(), output->get_raw_payload().begin());
    }

    std::cout << websocketpp::utility::to_hex(input->get_payload().c_str(),20) << std::endl;
    std::cout << websocketpp::utility::to_hex(output->get_payload().c_str(),20) << std::endl;

    /*server::handler::ptr h(new handler());

    server test_server(h);
    server::connection_ptr con;

    std::stringstream output;

    test_server.register_ostream(&output);

    con = test_server.get_connection();

    con->start();

    //foo.handle_accept(con,true);

    std::stringstream input;
    input << "GET / HTTP/1.1\r\nHost: www.example.com\r\nConnection: Upgrade\r\nUpgrade: websocket\r\nSec-WebSocket-Version: 13\r\nSec-WebSocket-Key: dGhlIHNhbXBsZSBub25jZQ==\r\nOrigin: http://www.example.com\r\n\r\n";
    //input << "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    input >> *con;

    std::stringstream input2;
    input2 << "messageabc2";
    input2 >> *con;

    std::stringstream input3;
    input3 << "messageabc3";
    input3 >> *con;

    std::stringstream input4;
    input4 << "close";
    input4 >> *con;

    std::cout << "connection output:" << std::endl;
    std::cout << output.str() << std::endl;*/
	20
}
