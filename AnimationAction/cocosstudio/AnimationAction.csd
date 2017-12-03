<GameFile>
  <PropertyGroup Name="AnimationAction" Type="Scene" ID="95c8392f-cd89-4083-96e9-2cf509f7bd17" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="10" Speed="1.0000">
        <Timeline ActionTag="177070515" Property="FileData">
          <TextureFrame FrameIndex="0" Tween="False">
            <TextureFile Type="PlistSubImage" Path="s101line01.png" Plist="scene101bg.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="5" Tween="False">
            <TextureFile Type="PlistSubImage" Path="s101line02.png" Plist="scene101bg.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="10" Tween="False">
            <TextureFile Type="PlistSubImage" Path="s101line01.png" Plist="scene101bg.plist" />
          </TextureFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="Scene" Tag="18" ctype="GameNodeObjectData">
        <Size X="1280.0000" Y="720.0000" />
        <Children>
          <AbstractNodeData Name="s101bgimg_1" ActionTag="508955799" Tag="19" IconVisible="False" ctype="SpriteObjectData">
            <Size X="1280.0000" Y="720.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="640.0000" Y="360.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="PlistSubImage" Path="s101bgimg.png" Plist="scene101bg.plist" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="Sprite_1" ActionTag="177070515" Tag="3" IconVisible="False" TopMargin="222.0000" BottomMargin="212.0000" ctype="SpriteObjectData">
            <Size X="1280.0000" Y="286.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="640.0000" Y="355.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.4931" />
            <PreSize X="1.0000" Y="0.3972" />
            <FileData Type="PlistSubImage" Path="s101line01.png" Plist="scene101bg.plist" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="BGM" ActionTag="-1054820227" Tag="18" IconVisible="True" LeftMargin="644.9065" RightMargin="635.0935" TopMargin="170.4307" BottomMargin="549.5693" Volume="1.0000" Loop="True" ctype="SimpleAudioObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position X="644.9065" Y="549.5693" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5038" Y="0.7633" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="SR_bg.mp3" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="BloodBar_1" ActionTag="1117902960" Tag="19" IconVisible="False" LeftMargin="1000.0000" RightMargin="80.0000" TopMargin="473.0000" BottomMargin="233.0000" ProgressInfo="100" ctype="LoadingBarObjectData">
            <Size X="200.0000" Y="14.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="1100.0000" Y="240.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="0" B="0" />
            <PrePosition X="0.8594" Y="0.3333" />
            <PreSize X="0.1563" Y="0.0194" />
            <ImageFileData Type="Default" Path="Default/LoadingBarFile.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="returnbtn" ActionTag="998692852" Tag="20" IconVisible="False" LeftMargin="38.7094" RightMargin="1166.2906" TopMargin="25.1807" BottomMargin="618.8193" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="45" Scale9Height="54" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="75.0000" Y="76.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="76.2094" Y="656.8193" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.0595" Y="0.9122" />
            <PreSize X="0.0586" Y="0.1056" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="PlistSubImage" Path="returnbtn.png" Plist="scene101bg.plist" />
            <NormalFileData Type="PlistSubImage" Path="returnbtn.png" Plist="scene101bg.plist" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="cuberbtn" ActionTag="-2117743682" Tag="22" IconVisible="False" LeftMargin="129.3699" RightMargin="1054.6301" TopMargin="19.6776" BottomMargin="613.3224" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="66" Scale9Height="65" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="96.0000" Y="87.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="177.3699" Y="656.8224" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1386" Y="0.9123" />
            <PreSize X="0.0750" Y="0.1208" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="PlistSubImage" Path="cuberbtn3.png" Plist="scene101bg.plist" />
            <PressedFileData Type="PlistSubImage" Path="cuberbtn2.png" Plist="scene101bg.plist" />
            <NormalFileData Type="PlistSubImage" Path="cuberbtn1.png" Plist="scene101bg.plist" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="replaybtn" ActionTag="1399061758" Tag="23" IconVisible="False" LeftMargin="1174.4806" RightMargin="29.5194" TopMargin="23.4074" BottomMargin="622.5926" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="46" Scale9Height="52" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="76.0000" Y="74.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="1212.4806" Y="659.5926" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.9473" Y="0.9161" />
            <PreSize X="0.0594" Y="0.1028" />
            <TextColor A="255" R="65" G="65" B="70" />
            <PressedFileData Type="PlistSubImage" Path="replaybtn.png" Plist="scene101bg.plist" />
            <NormalFileData Type="PlistSubImage" Path="replaybtn.png" Plist="scene101bg.plist" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>