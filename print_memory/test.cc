int main(){
case PaddleDType::INT64: {
    int64_t *pdata = static_cast<int64_t *>(out.data.data());
    int64_t *pdata_ref = static_cast<int64_t *>(ref_out.data.data());
    for (size_t j = 0; j < size; ++j) {
        EXPECT_EQ(pdata_ref[j], pdata[j]);
    }
    break;
}
}
