
ÿ#‰ùİy_X@R8"„Ló_óõÔ_I2_ÿ#uçâ_X@R8"„Ló_óõÔ_I2_ÿ#zwb|#Šw%¹×<­©İ¢>#Šw%¹×<nŠ,·ûb™êÿ¶)¬.†š>#Šw%¹×<Áæì¡É¶šr‰ßŠÜ¢·.†š>ÿ#Šw%¹×<Áæì¡É¶š±ç.®+rşz'x.†š>ÿ#Šw%¹×<Áæì¡É¶šr‰ÜººŞÌ¿‰Ş.†š>ÿ#Šw%¹×<Áæì¡É¶šr‰ÜººŞÌ¿²Ù.†š>ÿ#Šw%¹×<Áæì¡É¶š¶¶§²š+·ø¨²ÚŞj.†š>#Šw%¹×<Áæì¡É¶š±êïz.†š>#Šw%¹×<Š‹-­æ¦>#Šw%¹×<²Ëky©>ÿûr¥ç^›²‡$zÚi::r‰ÜººŞÌ::²Ù\¢w.®·§s;ÿûr¥ç^›²‡$zÚi::¶¶§²š+´::Š‹-­æ¦<r‰ÜººŞÌ>¶¶§²š+´;ÿûr¥ç^›²‡$zÚi::±êïz<r‰ÜººŞÌ,¶¶§²š+´>±êïz;·*^uçğy»(rG­¦::±êïz<Áæì¡É¶š::r‰ßŠ::rŠŞ>±êïz;ü*rV¬²§vW«:¦æå‰Ë®÷«::…©İ•ê{nŠ%½©bu«^(r‰çyËb¢_¦ÚÜ¢){²×::r‹­<<"…©İ•êïjXj×"<<²×::zwe;‰(r‰->ë_¢¸ Š()!"†Ûi:ÿü0À.{¦¦W.r‰"){r‰->±ë_²Ö­º(Áæì¡É¶š::†Ûi::²Ö­º_r‡^::äA 0Ä4);­ën®wÚ–Ç;}­ën®{k¹;}¾ˆ†Ûi(r‰çyËb¢_¦ÚÜ¢){²×::r‹­<<"…©İ•êá¶Ú"<<²×::zwe;}¾ˆ¢_–†(r‰çyËb¢_¦ÚÜ¢,¦Úè•_…©İ•ê){²×::r‹­<<"…©İ•êèœ_–†"<<²×::zwe;}¾ˆ¢_ºyhi(r‰çyËb¢_¦ÚÜ¢,¦Úç{_…©İ•ê){²×::r‹­<<"…©İ•êèœ_ºyhi"<<²×::zwe;}¾ˆ¢_¢—§(r‰çyËb¢_¦ÚÜ¢){²×::r‹­<<"…©İ•êèœ_¢—§"<<²×::zwe;}¾ˆ¢_}¨¥(r‰çyËb¢_¦ÚÜ¢){²×::r‹­<<"…©İ•êèœ_}¨¥"<<²×::zwe;}¾ˆ¢_™ë,j(r‰çyËb¢_¦ÚÜ¢,™ë,j_¦Úæ²){²×::r‹­<<"…©İ•êèœ_™ë,j"<<²×::zwe;}¾ˆ¢_rZ,x(r‰çyËb¢_¦ÚÜ¢){²×::r‹­<<"…©İ•êèœ_rZ,x"<<²×::zwe;}};*ü
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
