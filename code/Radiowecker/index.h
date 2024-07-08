//html for web pages
const char OPTION_entry[] PROGMEM = 
"<option value='%i' %s>%s %s</option>";

const char MAIN_page[] PROGMEM = R"=====(
<html>
<head>
<meta http-equiv='content-type' content='text/html; charset=UTF-8'>
<meta name='viewport' content='width=320' />
<link href = "https://code.jquery.com/ui/1.10.4/themes/ui-lightness/jquery-ui.css" rel = "stylesheet">
<script src = "https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>

<script>
$(function() {
  $(document).ready(getAll);
  $("#btn_save").click(saveSSID);
  $("#btn_reset").click(restartHost);
  $("#btn_test").click(testStation);
  $("#btn_updt").click(updateStation);
  $("#btn_restore").click(restoreStations);
  $("#btn_savealarm").click(setAlarms);
  $("#btn_cancelalarm").click(getAlarms);
  $("#stationlist").change(getStation);
});

function getAll() {
  getSSID();
  getStationList();
  getAlarms();
}

function getStationList() {
  $.ajax({
    type:"GET",
    url:"/cmd/stations",
    data:{},
    success: function(data){
      $("#stationlist").html(data);
      getStation();
    }
  });
}

function getStation() {
  $.ajax({
    type:"GET",url:"/cmd/getstation",
    data:{"stationid":$("#stationlist").val()},
    success: function(data){
      const parts = data.split("\n");
      $("#name_input").val(parts[0]);
      $("#url_input").val(parts[1]);
      $("#enable_input").prop("checked",(parts[2] == 1));
      $("#pos_input").val(parts[3]);
    }
  });
}

function updateStation() {
  const checked = $("#enable_input").prop("checked")?1:0;
  $.ajax({
    type:"GET",
    url:"/cmd/setstation",
    data:{"stationid":$("#stationlist").val(),
          "name":$("#name_input").val(),
          "url":$("#url_input").val(),
          "enabled":checked,
          "position":$("#pos_input").val()},
    success: function(data){
      const n = ( $("#enable_input").prop("checked"))?"&#x25cf; ":"&#x2002; "
      $( "#stationlist option:selected" ).html(n + $("#name_input").val());
      alert(data);
      getStationList();
    }
  });
}

function restoreStations() {
  $.ajax({
    type:"GET",
    url:"/cmd/restorestations",
    data:{},
    success: function(data){
      getStationList();
    }
  });
}


function testStation() {
  const checked = $("#enable_input").prop("checked")?1:0;
  $.ajax({
    type:"GET",
    url:"/cmd/teststation",
    data:{"url":$("#url_input").val()},
    success: function(data){
      alert("Mit OK beenden Sie den Test");
      endTest();
    },
    error: function() {
      alert("ERROR");
    }
  });
}

function endTest() {
  const checked = $("#enable_input").prop("checked")?1:0;
  $.ajax({
    type:"GET",
    url:"/cmd/endtest",
    data:{},
    success: function(data){
    }
  });
}

function getSSID() {
  $.ajax({
    type:"GET",
    url:"/cmd/getaccess",
    data:{},
    success: function(data){
      const parts = data.split("\n");
      $("#ssid_input").val(parts[0]);
      $("#pkey_input").val(parts[1]);
      $("#ntp_input").val(parts[2]);
    }
  });
}

function getAlarms() {
  $.ajax({
    type:"GET",
    url:"/cmd/getalarms",
    data:{},
    success: function(data){
      const parts = data.split("\n");
      for (var i = 0; i < 16; i++) {
        if ((i==0) || (i==8)) {
          $("#al"+i).val(parts[i]);
        } else {
          if (parts[i]=='1') {
            $("#al"+i).prop('checked',true);
          } else {
            $("#al"+i).prop('checked',false);
          }
        }
      }
    }
  });
}

function saveSSID() {
  $.ajax({
    type:"GET",
    url:"/cmd/setaccess",
    data:{"ssid":$("#ssid_input").val(),"pkey":$("#pkey_input").val(),"ntp":$("#ntp_input").val()},
    success: function(data){
      alert(data);
    }
  });
}

function setAlarms() {
  const vals = new Object();
  for (var i = 0; i < 16; i++) {
    if ((i == 0) || (i == 8)) {
      vals['al'+i] = $("#al"+i).val();
    } else {
      vals['al'+i] = $("#al"+i).prop("checked")?'1':'0';
    }
  }
  
  $.ajax({
    type:"GET",
    url:"/cmd/setalarms",
    data:vals,
    success: function(data){
      alert(data);
    }
  });
}

function restartHost() {
  $.ajax({
    type:"POST",
    url:"/cmd/restart",
    data:{},
  });
}

</script>
<style>
body {
  width:300px;
  font-family:arial;
}

button {
  width:110px;
  background-color:silver;
  border-radius:10px;
}

.theme {
  background-color:cadetblue;
  padding:10px;
  border-radius: 10px;
  border: 2px solid silver;
}

.confpane {
  width:280px;
  height:135px;
}

.selectpane {
  width:280px;
  height:20px;
  margin-top:10px;
  text-align:center;
}

.alarmpane {
  width:280px;
  height:124px;
  margin-top:10px;
}


.editpane {
  width:280px;
  height:164px;
  margin-top:10px;
}

.txtinput {
  position:absolute;
  left:90px;
  width:200px;
}

.numinput {
  position:absolute;
  left:160px;
  width:60px;
}

.urlinput {
  width:272px;
}

label {
  color:white;
  font-family:arial;
}

.slabel {
  font: 12px 'Arial Narrow';
}

</style>
</head>
<body>
<h1 style="text-align:center;">Web Radiowecker</h1>
<div class="confpane theme">
<div><label for="ssid_input">SSID:</label> <input id="ssid_input" class="txtinput"/></div>
<div style="padding-top:10px;"><label for="pkey_input">PKEY:</label> 
<input id="pkey_input" class="txtinput" type="password"/></div>
<div style="padding-top:10px;"><label for="ntp_input">NTP:</label> 
<input id="ntp_input" class="txtinput"/></div>
<div style="padding-top:10px;text-align:center">
<button id="btn_save" type="button">Speichern</button>
<button id="btn_reset" type="button" style="margin-left:20px;">Neustart</button></div>
<div style="padding-top:10px;text-align:center">
<button id="btn_restore" type="button" style="width:180px">Senderliste zurücksetzen</button></div>
</div>
<div class="alarmpane theme">
      <div>
        <label for="al0">Weckerzeit 1:</label>
        <input id="al0" type="time" class="numinput"/>
      </div>
      <div>
        <label for="al1" class="slabel">So</label>
        <input id="al1" type="checkbox"/>
        <label for="al2" class="slabel">Mo</label>
        <input id="al2" type="checkbox"/>
        <label for="al3" class="slabel">Di</label>
        <input id="al3" type="checkbox"/>
        <label for="al4" class="slabel">Mi</label>
        <input id="al4" type="checkbox"/>
        <label for="al5" class="slabel">Do</label>
        <input id="al5" type="checkbox"/>
        <label for="al6" class="slabel">Fr</label>
        <input id="al6" type="checkbox"/>
        <label for="al7" class="slabel">Sa</label>
        <input id="al7" type="checkbox"/>
      </div>
      <div>&nbsp;</div>
      <div>
        <label for="al8">Weckerzeit 2:</label>
        <input id="al8" type="time" class="numinput"/>
      </div>
      <div>
        <label for="al9" class="slabel">So</label>
        <input id="al9" type="checkbox"/>
        <label for="al10" class="slabel">Mo</label>
        <input id="al10" type="checkbox"/>
        <label for="al11" class="slabel">Di</label>
        <input id="al11" type="checkbox"/>
        <label for="al12" class="slabel">Mi</label>
        <input id="al12" type="checkbox"/>
        <label for="al13" class="slabel">Do</label>
        <input id="al13" type="checkbox"/>
        <label for="al14" class="slabel">Fr</label>
        <input id="al14" type="checkbox"/>
        <label for="al15" class="slabel">Sa</label>
        <input id="al15" type="checkbox"/>
      </div>
<div style="padding-top:10px;text-align:center">
<button id="btn_savealarm" type="button">Speichern</button>
<button id="btn_cancelalarm" type="button" style="margin-left:20px;">Rückgängig</button>
</div>
</div>
<div class="selectpane theme">
<select id="stationlist">
</select>
</div>
<div id="config" class="editpane theme">
<div><label for="name_input">Name:</label> <input id="name_input" class="txtinput"/></div>
<div style="padding-top:10px;"><label for="url_input">URL:</label><br> <input id="url_input" class="urlinput" /></div>
<div style="padding-top:10px;">
<label for="enable_input">Verwenden:</label><input id="enable_input" class="txtinput" type="checkbox"></div>
<div style="padding-top:10px;">
<label for="pos_input">Position:</label> <input id="pos_input" type="number" step="1" min="1" max="99" size="2" class="numinput"/></div>
<div style="padding-top:20px;text-align:center">
<button id="btn_test" type="button">Testen</button>
<button id="btn_updt" type="button" style="margin-left:20px;">Ändern</button>
</div>
</div>

</body>
</html>
)=====";

//*****************************************************************************************************************
const char CONFIG_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
<meta http-equiv='content-type' content='text/html; charset=UTF-8'>
<meta name='viewport' content='width=320' />
<style>
body {
  width:300px;
  font-family:arial;
}

button {
  width:110px;
  background-color:silver;
  border-radius:10px;
}

.theme {
  background-color:cadetblue;
  padding:10px;
  border-radius: 10px;
  border: 2px solid silver;
}

.confpane {
  width:280px;
  height:75px;
}


.txtinput {
  position:absolute;
  left:90px;
  width:200px;
}

.label {
  color:white;
  font-family:arial;
}

</style>
</head>
<body>
<h1 style="text-align:center;">Radionwecker WLAN</h1>
<form>
<div class="confpane theme">
<div><span class="label">SSID:</span> <input name="conf_ssid" class="txtinput"/></div>
<div style="padding-top:10px;"><span class="label">PKEY:</span> 
<input name="conf_pkey" class="txtinput" type="password"/></div>
<div style="padding-top:10px;text-align:center">
<button type="submit" name="reset">Neustart</button></div>
</div>
</body>
</html>
)=====";
