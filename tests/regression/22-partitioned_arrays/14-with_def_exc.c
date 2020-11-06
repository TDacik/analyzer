// PARAM: --sets solver td3 --enable ana.int.def_exc  --enable exp.partition-arrays.enabled  --set ana.activated "['base','expRelation']"
int main(void) {
    // Minimal and maximal in def_exc were broken. They are not directly used, but used in the MayBeLess and MayBeEqual queries, that
    // are in turn used by the partitioning arrays. This is why we run the arrays in combination with def_exc.
    t1();
    t2();
}

void t1() {
    int arr[10];
    int i = 0;
    arr[0] = 5;
    arr[1] = 5;
    arr[2] = 5;

    for(i=0; i < 9;i++) { }

    int j = arr[i];
    assert(j == 5); //UNKNOWN
}


void t2() {
    int arr[512];
    int i = 0;

    {
        arr[0] = 5;
        arr[1] = 5;
        arr[2] = 5;
        arr[3] = 5;
        arr[4] = 5;
        arr[5] = 5;
        arr[6] = 5;
        arr[7] = 5;
        arr[8] = 5;
        arr[9] = 5;
        arr[10] = 5;
        arr[11] = 5;
        arr[12] = 5;
        arr[13] = 5;
        arr[14] = 5;
        arr[15] = 5;
        arr[16] = 5;
        arr[17] = 5;
        arr[18] = 5;
        arr[19] = 5;
        arr[20] = 5;
        arr[21] = 5;
        arr[22] = 5;
        arr[23] = 5;
        arr[24] = 5;
        arr[25] = 5;
        arr[26] = 5;
        arr[27] = 5;
        arr[28] = 5;
        arr[29] = 5;
        arr[30] = 5;
        arr[31] = 5;
        arr[32] = 5;
        arr[33] = 5;
        arr[34] = 5;
        arr[35] = 5;
        arr[36] = 5;
        arr[37] = 5;
        arr[38] = 5;
        arr[39] = 5;
        arr[40] = 5;
        arr[41] = 5;
        arr[42] = 5;
        arr[43] = 5;
        arr[44] = 5;
        arr[45] = 5;
        arr[46] = 5;
        arr[47] = 5;
        arr[48] = 5;
        arr[49] = 5;
        arr[50] = 5;
        arr[51] = 5;
        arr[52] = 5;
        arr[53] = 5;
        arr[54] = 5;
        arr[55] = 5;
        arr[56] = 5;
        arr[57] = 5;
        arr[58] = 5;
        arr[59] = 5;
        arr[60] = 5;
        arr[61] = 5;
        arr[62] = 5;
        arr[63] = 5;
        arr[64] = 5;
        arr[65] = 5;
        arr[66] = 5;
        arr[67] = 5;
        arr[68] = 5;
        arr[69] = 5;
        arr[70] = 5;
        arr[71] = 5;
        arr[72] = 5;
        arr[73] = 5;
        arr[74] = 5;
        arr[75] = 5;
        arr[76] = 5;
        arr[77] = 5;
        arr[78] = 5;
        arr[79] = 5;
        arr[80] = 5;
        arr[81] = 5;
        arr[82] = 5;
        arr[83] = 5;
        arr[84] = 5;
        arr[85] = 5;
        arr[86] = 5;
        arr[87] = 5;
        arr[88] = 5;
        arr[89] = 5;
        arr[90] = 5;
        arr[91] = 5;
        arr[92] = 5;
        arr[93] = 5;
        arr[94] = 5;
        arr[95] = 5;
        arr[96] = 5;
        arr[97] = 5;
        arr[98] = 5;
        arr[99] = 5;
        arr[100] = 5;
        arr[101] = 5;
        arr[102] = 5;
        arr[103] = 5;
        arr[104] = 5;
        arr[105] = 5;
        arr[106] = 5;
        arr[107] = 5;
        arr[108] = 5;
        arr[109] = 5;
        arr[110] = 5;
        arr[111] = 5;
        arr[112] = 5;
        arr[113] = 5;
        arr[114] = 5;
        arr[115] = 5;
        arr[116] = 5;
        arr[117] = 5;
        arr[118] = 5;
        arr[119] = 5;
        arr[120] = 5;
        arr[121] = 5;
        arr[122] = 5;
        arr[123] = 5;
        arr[124] = 5;
        arr[125] = 5;
        arr[126] = 5;
        arr[127] = 5;
        arr[128] = 5;
        arr[129] = 5;
        arr[130] = 5;
        arr[131] = 5;
        arr[132] = 5;
        arr[133] = 5;
        arr[134] = 5;
        arr[135] = 5;
        arr[136] = 5;
        arr[137] = 5;
        arr[138] = 5;
        arr[139] = 5;
        arr[140] = 5;
        arr[141] = 5;
        arr[142] = 5;
        arr[143] = 5;
        arr[144] = 5;
        arr[145] = 5;
        arr[146] = 5;
        arr[147] = 5;
        arr[148] = 5;
        arr[149] = 5;
        arr[150] = 5;
        arr[151] = 5;
        arr[152] = 5;
        arr[153] = 5;
        arr[154] = 5;
        arr[155] = 5;
        arr[156] = 5;
        arr[157] = 5;
        arr[158] = 5;
        arr[159] = 5;
        arr[160] = 5;
        arr[161] = 5;
        arr[162] = 5;
        arr[163] = 5;
        arr[164] = 5;
        arr[165] = 5;
        arr[166] = 5;
        arr[167] = 5;
        arr[168] = 5;
        arr[169] = 5;
        arr[170] = 5;
        arr[171] = 5;
        arr[172] = 5;
        arr[173] = 5;
        arr[174] = 5;
        arr[175] = 5;
        arr[176] = 5;
        arr[177] = 5;
        arr[178] = 5;
        arr[179] = 5;
        arr[180] = 5;
        arr[181] = 5;
        arr[182] = 5;
        arr[183] = 5;
        arr[184] = 5;
        arr[185] = 5;
        arr[186] = 5;
        arr[187] = 5;
        arr[188] = 5;
        arr[189] = 5;
        arr[190] = 5;
        arr[191] = 5;
        arr[192] = 5;
        arr[193] = 5;
        arr[194] = 5;
        arr[195] = 5;
        arr[196] = 5;
        arr[197] = 5;
        arr[198] = 5;
        arr[199] = 5;
        arr[200] = 5;
        arr[201] = 5;
        arr[202] = 5;
        arr[203] = 5;
        arr[204] = 5;
        arr[205] = 5;
        arr[206] = 5;
        arr[207] = 5;
        arr[208] = 5;
        arr[209] = 5;
        arr[210] = 5;
        arr[211] = 5;
        arr[212] = 5;
        arr[213] = 5;
        arr[214] = 5;
        arr[215] = 5;
        arr[216] = 5;
        arr[217] = 5;
        arr[218] = 5;
        arr[219] = 5;
        arr[220] = 5;
        arr[221] = 5;
        arr[222] = 5;
        arr[223] = 5;
        arr[224] = 5;
        arr[225] = 5;
        arr[226] = 5;
        arr[227] = 5;
        arr[228] = 5;
        arr[229] = 5;
        arr[230] = 5;
        arr[231] = 5;
        arr[232] = 5;
        arr[233] = 5;
        arr[234] = 5;
        arr[235] = 5;
        arr[236] = 5;
        arr[237] = 5;
        arr[238] = 5;
        arr[239] = 5;
        arr[240] = 5;
        arr[241] = 5;
        arr[242] = 5;
        arr[243] = 5;
        arr[244] = 5;
        arr[245] = 5;
        arr[246] = 5;
        arr[247] = 5;
        arr[248] = 5;
        arr[249] = 5;
        arr[250] = 5;
        arr[251] = 5;
        arr[252] = 5;
        arr[253] = 5;
        arr[254] = 5;
        arr[255] = 5;
    }

    for(i=0; i < 511; i++) { }
    int j = arr[i];
    assert(j==5); //UNKNOWN
}
