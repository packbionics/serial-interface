<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile doxygen_version="1.9.1">
  <compound kind="class">
    <name>serial::ImuFrame</name>
    <filename>classserial_1_1ImuFrame.html</filename>
    <member kind="function">
      <type></type>
      <name>ImuFrame</name>
      <anchorfile>classserial_1_1ImuFrame.html</anchorfile>
      <anchor>a901c53869d11ce131b82eba9d092f7ae</anchor>
      <arglist>(const std::vector&lt; double &gt; orientation, const std::vector&lt; double &gt; &amp;linAccel, const std::vector&lt; double &gt; &amp;angVel)</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; double &gt;</type>
      <name>getOrientation</name>
      <anchorfile>classserial_1_1ImuFrame.html</anchorfile>
      <anchor>a89da6509d5576a0881244e0d411b4fe7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; double &gt;</type>
      <name>getLinear</name>
      <anchorfile>classserial_1_1ImuFrame.html</anchorfile>
      <anchor>a5688dbfcdc84fc1e0c794b003fdb9051</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; double &gt;</type>
      <name>getAngular</name>
      <anchorfile>classserial_1_1ImuFrame.html</anchorfile>
      <anchor>a60169f601fa558b6cb943fda4494eca8</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>serial::LibSerialBridge</name>
    <filename>classserial_1_1LibSerialBridge.html</filename>
    <member kind="function">
      <type></type>
      <name>LibSerialBridge</name>
      <anchorfile>classserial_1_1LibSerialBridge.html</anchorfile>
      <anchor>abe4c2c3168d7b749808ae53cd4b4259f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>LibSerialBridge</name>
      <anchorfile>classserial_1_1LibSerialBridge.html</anchorfile>
      <anchor>a23215f48a0cd3890d7be59dd8f9550ed</anchor>
      <arglist>(std::string name, LibSerial::BaudRate baudRate)</arglist>
    </member>
    <member kind="function">
      <type>ImuPtr</type>
      <name>getImu</name>
      <anchorfile>classserial_1_1LibSerialBridge.html</anchorfile>
      <anchor>a7a256f66ae387344a7f000647c96bfd5</anchor>
      <arglist>(size_t index)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getKneeAngle</name>
      <anchorfile>classserial_1_1LibSerialBridge.html</anchorfile>
      <anchor>aa729f9ede7630b6a46c7c6aed21daea5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>updateInput</name>
      <anchorfile>classserial_1_1LibSerialBridge.html</anchorfile>
      <anchor>ae330753f53e84adfce91912f1d54887d</anchor>
      <arglist>(const std::vector&lt; double &gt; inputs)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>update</name>
      <anchorfile>classserial_1_1LibSerialBridge.html</anchorfile>
      <anchor>afe11482b0ccb50faf7edeb078959e554</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
</tagfile>
