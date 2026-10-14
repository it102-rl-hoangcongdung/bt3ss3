#include <stdio.h>

int main() {
    int tuoi;
    int mac_phim;
    int suat_chieu;
    int loai_ghe;
    int la_ngay_thuong;
    int doi_tuong;
    
    double gia_ve_goc = 0.0;
    double phu_thu_ghe = 0.0;
    double tien_giam = 0.0;
    double tong_tien = 0.0;
    
    printf("=== HỆ THỐNG QUẢN LÝ BÁN VÉ CGV CINEMA ===\n");
    
    printf("Nhập tuổi của khách hàng: ");
    if (scanf("%d", &tuoi) != 1) return 0;
    
    if (tuoi < 0 || tuoi > 120) {
        printf("Lỗi: Số tuổi nhập vào không hợp lệ!\n");
        return 0;
    }
    
    printf("Nhập mác phim (1: P, 2: T16, 3: T18): ");
    if (scanf("%d", &mac_phim) != 1) return 0;
    
    if (mac_phim == 2) {
        if (tuoi < 16) {
            printf("Từ chối bán vé: Phim T16 yêu cầu khán giả từ 16 tuổi trở lên!\n");
            return 0;
        }
    } else if (mac_phim == 3) {
        if (tuoi < 18) {
            printf("Từ chối bán vé: Phim T18 cấm khán giả dưới 18 tuổi!\n");
            return 0;
        }
    } else if (mac_phim != 1) {
        printf("Lỗi: Mã phân loại phim không hợp lệ!\n");
        return 0;
    }
    
    printf("Nhập suất chiếu (1: Sáng, 2: Chiều, 3: Tối): ");
    if (scanf("%d", &suat_chieu) != 1) return 0;
    
    switch (suat_chieu) {
        case 1:
            gia_ve_goc = 70000;
            break;
        case 2:
            gia_ve_goc = 90000;
            break;
        case 3:
            gia_ve_goc = 120000;
            break;
        default:
            printf("Lỗi: Lựa chọn suất chiếu không nằm trong menu!\n");
            return 0;
    }
    
    printf("Nhập loại ghế (1: Thường, 2: VIP, 3: Couple): ");
    if (scanf("%d", &loai_ghe) != 1) return 0;
    
    if (loai_ghe == 1) {
        phu_thu_ghe = 0;
    } else if (loai_ghe == 2) {
        phu_thu_ghe = 15000;
    } else if (loai_ghe == 3) {
        phu_thu_ghe = 30000;
    } else {
        printf("Lỗi: Loại ghế không hợp lệ!\n");
        return 0;
    }
    
    printf("Có phải ngày thường không? (1: Có, 0: Không): ");
    if (scanf("%d", &la_ngay_thuong) != 1) return 0;
    
    printf("Nhập đối tượng (1: HSSV, 2: Người cao tuổi, 3: Thường): ");
    if (scanf("%d", &doi_tuong) != 1) return 0;
    
    if (la_ngay_thuong == 1) {
        if (doi_tuong == 1) {
            tien_giam = gia_ve_goc * 0.20;
        } else if (doi_tuong == 2 || tuoi >= 60) {
            tien_giam = gia_ve_goc * 0.30;
        } else {
            tien_giam = 0;
        }
    } else {
        tien_giam = 0;
    }
    
    tong_tien = (gia_ve_goc - tien_giam) + phu_thu_ghe;
    
    printf("--------------------------------------------------\n");
    printf("HÓA ĐƠN THANH TOÁN VÉ PHIM\n");
    printf("--------------------------------------------------\n");
    printf("Khán giả : %d tuổi ", tuoi);
    if (mac_phim == 1) printf("(Đủ điều kiện xem phim P)\n");
    else if (mac_phim == 2) printf("(Đủ điều kiện xem phim T16)\n");
    else if (mac_phim == 3) printf("(Đủ điều kiện xem phim T18)\n");
    
    if (suat_chieu == 1) printf("Suất chiếu : Suất Sáng (Trước 12h)\n");
    else if (suat_chieu == 2) printf("Suất chiếu : Suất Chiều (12h - 17h)\n");
    else if (suat_chieu == 3) printf("Suất chiếu : Suất Tối / Blockbuster\n");
    
    if (loai_ghe == 1) printf("Loại ghế : Ghế Thường\n");
    else if (loai_ghe == 2) printf("Loại ghế : Ghế VIP\n");
    else if (loai_ghe == 3) printf("Loại ghế : Ghế Couple\n");
    
    printf("--------------------------------------------------\n");
    printf("Giá vé gốc : %.0f VNĐ\n", gia_ve_goc);
    
    if (la_ngay_thuong == 1 && doi_tuong == 1) {
        printf("Giảm giá (20%) : -%.0f VNĐ\n", tien_giam);
    } else if (la_ngay_thuong == 1 && (doi_tuong == 2 || tuoi >= 60)) {
        printf("Giảm giá (30%) : -%.0f VNĐ\n", tien_giam);
    } else {
        printf("Giảm giá : 0 VNĐ\n");
    }
    
    if (loai_ghe == 2) {
        printf("Phụ thu ghế VIP : +%.0f VNĐ\n", phu_thu_ghe);
    } else if (loai_ghe == 3) {
        printf("Phụ thu ghế Couple : +%.0f VNĐ\n", phu_thu_ghe);
    } else {
        printf("Phụ thu ghế : 0 VNĐ\n");
    }
    
    printf("--------------------------------------------------\n");
    printf("TỔNG TIỀN THANH TOÁN: %.0f VNĐ\n", tong_tien);
    printf("--------------------------------------------------\n");
    
    return 0;
}