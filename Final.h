/////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Apr  7 20:32:46 2021 by ROOT version 5.34/36
// from TTree T/titled by PHOOL
// found on file: /phenix/plhf/lbichon/taxi/Run14AuAu200MuonsMBPro109/17112/hadd/merged.root
//////////////////////////////////////////////////////////

#ifndef Final_h
#define Final_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <TObject.h>

// Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMaxCompactEPArray = 20;
   const Int_t kMaxDiMuons = 16;

class Final {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
 //CompactEventPlane *DST/COMPACTEPTREE;
   UInt_t          fUniqueID;
   UInt_t          fBits;
   Int_t           evt_cent;
   Float_t         evt_bbcz;
   Int_t           evt_trig;
   Int_t           CompactEPArray_;
   UInt_t          CompactEPArray_fUniqueID[kMaxCompactEPArray];   //[CompactEPArray_]
   UInt_t          CompactEPArray_fBits[kMaxCompactEPArray];   //[CompactEPArray_]
   Int_t           CompactEPArray_idcode[kMaxCompactEPArray];   //[CompactEPArray_]
   Float_t         CompactEPArray_psi[kMaxCompactEPArray];   //[CompactEPArray_]
 //DiMuonContainer_v13 *DST/DiMuonContainer;
   UInt_t          fUniqueID;
   UInt_t          fBits;
   UInt_t          nDiMuons;
   Int_t           DiMuons_;
   UInt_t          DiMuons_fUniqueID[kMaxDiMuons];   //[DiMuons_]
   UInt_t          DiMuons_fBits[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_mass[kMaxDiMuons];   //[DiMuons_]
   Short_t         DiMuons_charge[kMaxDiMuons];   //[DiMuons_]
   Bool_t          DiMuons_same_event[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_rapidity[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_X0[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Y0[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Z0[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Px[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Py[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Pz[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_phi_dca[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_dca_r[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_dca_z[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Evt_vtxchi2[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Evt_vtxoor[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_costhCS[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_costhGJ[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_costhHX[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_phiCS[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_phiGJ[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_phiHX[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_px[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_py[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_pz[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_rapidity[kMaxDiMuons];   //[DiMuons_]
   Short_t         DiMuons_Tr0_trhits[kMaxDiMuons];   //[DiMuons_]
   Short_t         DiMuons_Tr0_idhits[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_DG0[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_DDG0[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_DS3[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_trchi2[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_idchi2[kMaxDiMuons];   //[DiMuons_]
   Short_t         DiMuons_Tr0_ntrhits[kMaxDiMuons];   //[DiMuons_]
   Short_t         DiMuons_Tr0_nidhits[kMaxDiMuons];   //[DiMuons_]
   Short_t         DiMuons_Tr0_lastgap[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_xst1[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_xst2[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_xst3[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_yst1[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_yst2[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_yst3[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_idx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_idy[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_st1px[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_st1py[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_st1pz[kMaxDiMuons];   //[DiMuons_]
   Bool_t          DiMuons_Tr0_MUID1D[kMaxDiMuons];   //[DiMuons_]
   Bool_t          DiMuons_Tr0_MUID1S[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_dca_z[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_dca_r[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_px[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_py[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_pz[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_rapidity[kMaxDiMuons];   //[DiMuons_]
   Short_t         DiMuons_Tr1_trhits[kMaxDiMuons];   //[DiMuons_]
   Short_t         DiMuons_Tr1_idhits[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_DG0[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_DDG0[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_DS3[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_trchi2[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_idchi2[kMaxDiMuons];   //[DiMuons_]
   Short_t         DiMuons_Tr1_ntrhits[kMaxDiMuons];   //[DiMuons_]
   Short_t         DiMuons_Tr1_nidhits[kMaxDiMuons];   //[DiMuons_]
   Short_t         DiMuons_Tr1_lastgap[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_xst1[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_xst2[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_xst3[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_yst1[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_yst2[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_yst3[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_idx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_idy[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_st1px[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_st1py[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_st1pz[kMaxDiMuons];   //[DiMuons_]
   Bool_t          DiMuons_Tr1_MUID1D[kMaxDiMuons];   //[DiMuons_]
   Bool_t          DiMuons_Tr1_MUID1S[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_dca_z[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_dca_r[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_mass_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_mass_fvtxmutr[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_x0_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_y0_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_z0_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_px_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_py_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_pz_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_x0_fvtxmutr[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_y0_fvtxmutr[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_z0_fvtxmutr[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_px_fvtxmutr[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_py_fvtxmutr[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_pz_fvtxmutr[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_nhits_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_dphi_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_dtheta_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_dr_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_chi2_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_chi2_fvtxmutr[kMaxDiMuons];   //[DiMuons_]
   UInt_t          DiMuons_Tr0_fvtx_strip[kMaxDiMuons][4];   //[DiMuons_]
   ULong_t         DiMuons_Tr0_nfvtx_tracklets_cone[kMaxDiMuons];   //[DiMuons_]
   ULong_t         DiMuons_Tr0_nfvtx_clusters_cone[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_dca_phi[kMaxDiMuons];   //[DiMuons_]
   UShort_t        DiMuons_Tr0_clusters_size1[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_x0_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_y0_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_z0_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_px_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_py_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_pz_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_x0_fvtxmutr[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_y0_fvtxmutr[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_z0_fvtxmutr[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_px_fvtxmutr[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_py_fvtxmutr[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_pz_fvtxmutr[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_nhits_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_dphi_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_dtheta_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_dr_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_chi2_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_chi2_fvtxmutr[kMaxDiMuons];   //[DiMuons_]
   UInt_t          DiMuons_Tr1_fvtx_strip[kMaxDiMuons][4];   //[DiMuons_]
   ULong_t         DiMuons_Tr1_nfvtx_tracklets_cone[kMaxDiMuons];   //[DiMuons_]
   ULong_t         DiMuons_Tr1_nfvtx_clusters_cone[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_dca_phi[kMaxDiMuons];   //[DiMuons_]
   UShort_t        DiMuons_Tr1_clusters_size1[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Px_fvtxmutr[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Py_fvtxmutr[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Pz_fvtxmutr[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_rapidity_fvtxmutr[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Evt_vtxchi2_fvtxmutr[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_X0_fvtxmutr[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Y0_fvtxmutr[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Z0_fvtxmutr[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_X0_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Y0_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Z0_fvtx[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_x0[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_x0[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_y0[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_y0[kMaxDiMuons];   //[DiMuons_]
   Short_t         DiMuons_Tr0_n_matchings[kMaxDiMuons];   //[DiMuons_]
   Short_t         DiMuons_Tr1_n_matchings[kMaxDiMuons];   //[DiMuons_]
   Short_t         DiMuons_Tr0_vtx_index[kMaxDiMuons];   //[DiMuons_]
   Short_t         DiMuons_Tr1_vtx_index[kMaxDiMuons];   //[DiMuons_]
   UShort_t        DiMuons_Tr0_hit_pattern[kMaxDiMuons];   //[DiMuons_]
   UShort_t        DiMuons_Tr1_hit_pattern[kMaxDiMuons];   //[DiMuons_]
   ULong_t         DiMuons_Tr0_track_id[kMaxDiMuons];   //[DiMuons_]
   ULong_t         DiMuons_Tr1_track_id[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_maxres_sigma[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_maxres_sigma[kMaxDiMuons];   //[DiMuons_]
   Bool_t          DiMuons_Tr0_is_sfvtx[kMaxDiMuons];   //[DiMuons_]
   Bool_t          DiMuons_Tr1_is_sfvtx[kMaxDiMuons];   //[DiMuons_]
   Bool_t          DiMuons_Tr0_best_fvtxmutr_match[kMaxDiMuons];   //[DiMuons_]
   Bool_t          DiMuons_Tr1_best_fvtxmutr_match[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_x_fvtxproj[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_y_fvtxproj[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_x_fvtxproj[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_y_fvtxproj[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr0_idpanel[kMaxDiMuons];   //[DiMuons_]
   Float_t         DiMuons_Tr1_idpanel[kMaxDiMuons];   //[DiMuons_]
   Float_t         Evt_vtxX;
   Float_t         Evt_vtxY;
   Float_t         Evt_vtxZ;
   Float_t         Evt_vtxX_Err;
   Float_t         Evt_vtxY_Err;
   Float_t         Evt_vtxZ_Err;
   Float_t         Evt_fvtxX;
   Float_t         Evt_fvtxY;
   Float_t         Evt_fvtxZ;
   Float_t         Evt_fvtxX_Err;
   Float_t         Evt_fvtxY_Err;
   Float_t         Evt_fvtxZ_Err;
   Float_t         Evt_fvtxX2;
   Float_t         Evt_fvtxY2;
   Float_t         Evt_fvtxZ2;
   Float_t         Evt_bbcZ;
   Float_t         Evt_bbcZ_Err;
   Float_t         Evt_Cent;
   Short_t         Evt_Mult_FVTXS;
   Short_t         Evt_Mult_FVTXN;
   Short_t         Evt_Mult_sFVTXS;
   Short_t         Evt_Mult_sFVTXN;
   Short_t         Evt_Mult_SVX;
   Float_t         Evt_BbcTdcMean_S;
   Float_t         Evt_BbcTdcMean_N;
   Float_t         Evt_BbcTdcRMS_S;
   Float_t         Evt_BbcTdcRMS_N;
   Float_t         Evt_BbcTdcMode_S;
   Float_t         Evt_BbcTdcMode_N;
   Short_t         Evt_BbcTdcnPeaks_S;
   Short_t         Evt_BbcTdcnPeaks_N;
 //EventHeaderv3   *DST/EventHeader;
   UInt_t          fUniqueID;
   UInt_t          fBits;
   Int_t           EvtSequence;
   Int_t           EvtType;
   Long_t          TimeStamp;
 //set<unsigned int> badpackets;
 //TrigLvl1v3      *DST/TrigLvl1;
   UInt_t          fUniqueID;
   UInt_t          fBits;
   UInt_t          lvl1_trigraw;
   UInt_t          lvl1_triglive;
   UInt_t          lvl1_trigscaled;
   UInt_t          lvl1_clock_cross;
   UInt_t          lvl1_rbits[5];
   UInt_t          beamclk[2];
 //SyncObjectv2    *DST/Sync;
   UInt_t          fUniqueID;
   UInt_t          fBits;
   Int_t           eventcounter;
   Int_t           eventnumber;
   Int_t           runnumber;
   Int_t           segmentnumber;

   // List of branches
   TBranch        *b_DST_COMPACTEPTREE_fUniqueID;   //!
   TBranch        *b_DST_COMPACTEPTREE_fBits;   //!
   TBranch        *b_DST_COMPACTEPTREE_evt_cent;   //!
   TBranch        *b_DST_COMPACTEPTREE_evt_bbcz;   //!
   TBranch        *b_DST_COMPACTEPTREE_evt_trig;   //!
   TBranch        *b_DST_COMPACTEPTREE_CompactEPArray_;   //!
   TBranch        *b_CompactEPArray_fUniqueID;   //!
   TBranch        *b_CompactEPArray_fBits;   //!
   TBranch        *b_CompactEPArray_idcode;   //!
   TBranch        *b_CompactEPArray_psi;   //!
   TBranch        *b_DST_DiMuonContainer_fUniqueID;   //!
   TBranch        *b_DST_DiMuonContainer_fBits;   //!
   TBranch        *b_DST_DiMuonContainer_nDiMuons;   //!
   TBranch        *b_DST_DiMuonContainer_DiMuons_;   //!
   TBranch        *b_DiMuons_fUniqueID;   //!
   TBranch        *b_DiMuons_fBits;   //!
   TBranch        *b_DiMuons_mass;   //!
   TBranch        *b_DiMuons_charge;   //!
   TBranch        *b_DiMuons_same_event;   //!
   TBranch        *b_DiMuons_rapidity;   //!
   TBranch        *b_DiMuons_X0;   //!
   TBranch        *b_DiMuons_Y0;   //!
   TBranch        *b_DiMuons_Z0;   //!
   TBranch        *b_DiMuons_Px;   //!
   TBranch        *b_DiMuons_Py;   //!
   TBranch        *b_DiMuons_Pz;   //!
   TBranch        *b_DiMuons_phi_dca;   //!
   TBranch        *b_DiMuons_dca_r;   //!
   TBranch        *b_DiMuons_dca_z;   //!
   TBranch        *b_DiMuons_Evt_vtxchi2;   //!
   TBranch        *b_DiMuons_Evt_vtxoor;   //!
   TBranch        *b_DiMuons_costhCS;   //!
   TBranch        *b_DiMuons_costhGJ;   //!
   TBranch        *b_DiMuons_costhHX;   //!
   TBranch        *b_DiMuons_phiCS;   //!
   TBranch        *b_DiMuons_phiGJ;   //!
   TBranch        *b_DiMuons_phiHX;   //!
   TBranch        *b_DiMuons_Tr0_px;   //!
   TBranch        *b_DiMuons_Tr0_py;   //!
   TBranch        *b_DiMuons_Tr0_pz;   //!
   TBranch        *b_DiMuons_Tr0_rapidity;   //!
   TBranch        *b_DiMuons_Tr0_trhits;   //!
   TBranch        *b_DiMuons_Tr0_idhits;   //!
   TBranch        *b_DiMuons_Tr0_DG0;   //!
   TBranch        *b_DiMuons_Tr0_DDG0;   //!
   TBranch        *b_DiMuons_Tr0_DS3;   //!
   TBranch        *b_DiMuons_Tr0_trchi2;   //!
   TBranch        *b_DiMuons_Tr0_idchi2;   //!
   TBranch        *b_DiMuons_Tr0_ntrhits;   //!
   TBranch        *b_DiMuons_Tr0_nidhits;   //!
   TBranch        *b_DiMuons_Tr0_lastgap;   //!
   TBranch        *b_DiMuons_Tr0_xst1;   //!
   TBranch        *b_DiMuons_Tr0_xst2;   //!
   TBranch        *b_DiMuons_Tr0_xst3;   //!
   TBranch        *b_DiMuons_Tr0_yst1;   //!
   TBranch        *b_DiMuons_Tr0_yst2;   //!
   TBranch        *b_DiMuons_Tr0_yst3;   //!
   TBranch        *b_DiMuons_Tr0_idx;   //!
   TBranch        *b_DiMuons_Tr0_idy;   //!
   TBranch        *b_DiMuons_Tr0_st1px;   //!
   TBranch        *b_DiMuons_Tr0_st1py;   //!
   TBranch        *b_DiMuons_Tr0_st1pz;   //!
   TBranch        *b_DiMuons_Tr0_MUID1D;   //!
   TBranch        *b_DiMuons_Tr0_MUID1S;   //!
   TBranch        *b_DiMuons_Tr0_dca_z;   //!
   TBranch        *b_DiMuons_Tr0_dca_r;   //!
   TBranch        *b_DiMuons_Tr1_px;   //!
   TBranch        *b_DiMuons_Tr1_py;   //!
   TBranch        *b_DiMuons_Tr1_pz;   //!
   TBranch        *b_DiMuons_Tr1_rapidity;   //!
   TBranch        *b_DiMuons_Tr1_trhits;   //!
   TBranch        *b_DiMuons_Tr1_idhits;   //!
   TBranch        *b_DiMuons_Tr1_DG0;   //!
   TBranch        *b_DiMuons_Tr1_DDG0;   //!
   TBranch        *b_DiMuons_Tr1_DS3;   //!
   TBranch        *b_DiMuons_Tr1_trchi2;   //!
   TBranch        *b_DiMuons_Tr1_idchi2;   //!
   TBranch        *b_DiMuons_Tr1_ntrhits;   //!
   TBranch        *b_DiMuons_Tr1_nidhits;   //!
   TBranch        *b_DiMuons_Tr1_lastgap;   //!
   TBranch        *b_DiMuons_Tr1_xst1;   //!
   TBranch        *b_DiMuons_Tr1_xst2;   //!
   TBranch        *b_DiMuons_Tr1_xst3;   //!
   TBranch        *b_DiMuons_Tr1_yst1;   //!
   TBranch        *b_DiMuons_Tr1_yst2;   //!
   TBranch        *b_DiMuons_Tr1_yst3;   //!
   TBranch        *b_DiMuons_Tr1_idx;   //!
   TBranch        *b_DiMuons_Tr1_idy;   //!
   TBranch        *b_DiMuons_Tr1_st1px;   //!
   TBranch        *b_DiMuons_Tr1_st1py;   //!
   TBranch        *b_DiMuons_Tr1_st1pz;   //!
   TBranch        *b_DiMuons_Tr1_MUID1D;   //!
   TBranch        *b_DiMuons_Tr1_MUID1S;   //!
   TBranch        *b_DiMuons_Tr1_dca_z;   //!
   TBranch        *b_DiMuons_Tr1_dca_r;   //!
   TBranch        *b_DiMuons_mass_fvtx;   //!
   TBranch        *b_DiMuons_mass_fvtxmutr;   //!
   TBranch        *b_DiMuons_Tr0_x0_fvtx;   //!
   TBranch        *b_DiMuons_Tr0_y0_fvtx;   //!
   TBranch        *b_DiMuons_Tr0_z0_fvtx;   //!
   TBranch        *b_DiMuons_Tr0_px_fvtx;   //!
   TBranch        *b_DiMuons_Tr0_py_fvtx;   //!
   TBranch        *b_DiMuons_Tr0_pz_fvtx;   //!
   TBranch        *b_DiMuons_Tr0_x0_fvtxmutr;   //!
   TBranch        *b_DiMuons_Tr0_y0_fvtxmutr;   //!
   TBranch        *b_DiMuons_Tr0_z0_fvtxmutr;   //!
   TBranch        *b_DiMuons_Tr0_px_fvtxmutr;   //!
   TBranch        *b_DiMuons_Tr0_py_fvtxmutr;   //!
   TBranch        *b_DiMuons_Tr0_pz_fvtxmutr;   //!
   TBranch        *b_DiMuons_Tr0_nhits_fvtx;   //!
   TBranch        *b_DiMuons_Tr0_dphi_fvtx;   //!
   TBranch        *b_DiMuons_Tr0_dtheta_fvtx;   //!
   TBranch        *b_DiMuons_Tr0_dr_fvtx;   //!
   TBranch        *b_DiMuons_Tr0_chi2_fvtx;   //!
   TBranch        *b_DiMuons_Tr0_chi2_fvtxmutr;   //!
   TBranch        *b_DiMuons_Tr0_fvtx_strip;   //!
   TBranch        *b_DiMuons_Tr0_nfvtx_tracklets_cone;   //!
   TBranch        *b_DiMuons_Tr0_nfvtx_clusters_cone;   //!
   TBranch        *b_DiMuons_Tr0_dca_phi;   //!
   TBranch        *b_DiMuons_Tr0_clusters_size1;   //!
   TBranch        *b_DiMuons_Tr1_x0_fvtx;   //!
   TBranch        *b_DiMuons_Tr1_y0_fvtx;   //!
   TBranch        *b_DiMuons_Tr1_z0_fvtx;   //!
   TBranch        *b_DiMuons_Tr1_px_fvtx;   //!
   TBranch        *b_DiMuons_Tr1_py_fvtx;   //!
   TBranch        *b_DiMuons_Tr1_pz_fvtx;   //!
   TBranch        *b_DiMuons_Tr1_x0_fvtxmutr;   //!
   TBranch        *b_DiMuons_Tr1_y0_fvtxmutr;   //!
   TBranch        *b_DiMuons_Tr1_z0_fvtxmutr;   //!
   TBranch        *b_DiMuons_Tr1_px_fvtxmutr;   //!
   TBranch        *b_DiMuons_Tr1_py_fvtxmutr;   //!
   TBranch        *b_DiMuons_Tr1_pz_fvtxmutr;   //!
   TBranch        *b_DiMuons_Tr1_nhits_fvtx;   //!
   TBranch        *b_DiMuons_Tr1_dphi_fvtx;   //!
   TBranch        *b_DiMuons_Tr1_dtheta_fvtx;   //!
   TBranch        *b_DiMuons_Tr1_dr_fvtx;   //!
   TBranch        *b_DiMuons_Tr1_chi2_fvtx;   //!
   TBranch        *b_DiMuons_Tr1_chi2_fvtxmutr;   //!
   TBranch        *b_DiMuons_Tr1_fvtx_strip;   //!
   TBranch        *b_DiMuons_Tr1_nfvtx_tracklets_cone;   //!
   TBranch        *b_DiMuons_Tr1_nfvtx_clusters_cone;   //!
   TBranch        *b_DiMuons_Tr1_dca_phi;   //!
   TBranch        *b_DiMuons_Tr1_clusters_size1;   //!
   TBranch        *b_DiMuons_Px_fvtxmutr;   //!
   TBranch        *b_DiMuons_Py_fvtxmutr;   //!
   TBranch        *b_DiMuons_Pz_fvtxmutr;   //!
   TBranch        *b_DiMuons_rapidity_fvtxmutr;   //!
   TBranch        *b_DiMuons_Evt_vtxchi2_fvtxmutr;   //!
   TBranch        *b_DiMuons_X0_fvtxmutr;   //!
   TBranch        *b_DiMuons_Y0_fvtxmutr;   //!
   TBranch        *b_DiMuons_Z0_fvtxmutr;   //!
   TBranch        *b_DiMuons_X0_fvtx;   //!
   TBranch        *b_DiMuons_Y0_fvtx;   //!
   TBranch        *b_DiMuons_Z0_fvtx;   //!
   TBranch        *b_DiMuons_Tr0_x0;   //!
   TBranch        *b_DiMuons_Tr1_x0;   //!
   TBranch        *b_DiMuons_Tr0_y0;   //!
   TBranch        *b_DiMuons_Tr1_y0;   //!
   TBranch        *b_DiMuons_Tr0_n_matchings;   //!
   TBranch        *b_DiMuons_Tr1_n_matchings;   //!
   TBranch        *b_DiMuons_Tr0_vtx_index;   //!
   TBranch        *b_DiMuons_Tr1_vtx_index;   //!
   TBranch        *b_DiMuons_Tr0_hit_pattern;   //!
   TBranch        *b_DiMuons_Tr1_hit_pattern;   //!
   TBranch        *b_DiMuons_Tr0_track_id;   //!
   TBranch        *b_DiMuons_Tr1_track_id;   //!
   TBranch        *b_DiMuons_Tr0_maxres_sigma;   //!
   TBranch        *b_DiMuons_Tr1_maxres_sigma;   //!
   TBranch        *b_DiMuons_Tr0_is_sfvtx;   //!
   TBranch        *b_DiMuons_Tr1_is_sfvtx;   //!
   TBranch        *b_DiMuons_Tr0_best_fvtxmutr_match;   //!
   TBranch        *b_DiMuons_Tr1_best_fvtxmutr_match;   //!
   TBranch        *b_DiMuons_Tr0_x_fvtxproj;   //!
   TBranch        *b_DiMuons_Tr0_y_fvtxproj;   //!
   TBranch        *b_DiMuons_Tr1_x_fvtxproj;   //!
   TBranch        *b_DiMuons_Tr1_y_fvtxproj;   //!
   TBranch        *b_DiMuons_Tr0_idpanel;   //!
   TBranch        *b_DiMuons_Tr1_idpanel;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_vtxX;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_vtxY;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_vtxZ;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_vtxX_Err;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_vtxY_Err;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_vtxZ_Err;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_fvtxX;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_fvtxY;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_fvtxZ;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_fvtxX_Err;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_fvtxY_Err;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_fvtxZ_Err;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_fvtxX2;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_fvtxY2;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_fvtxZ2;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_bbcZ;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_bbcZ_Err;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_Cent;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_Mult_FVTXS;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_Mult_FVTXN;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_Mult_sFVTXS;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_Mult_sFVTXN;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_Mult_SVX;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_BbcTdcMean_S;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_BbcTdcMean_N;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_BbcTdcRMS_S;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_BbcTdcRMS_N;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_BbcTdcMode_S;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_BbcTdcMode_N;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_BbcTdcnPeaks_S;   //!
   TBranch        *b_DST_DiMuonContainer_Evt_BbcTdcnPeaks_N;   //!
   TBranch        *b_DST_EventHeader_fUniqueID;   //!
   TBranch        *b_DST_EventHeader_fBits;   //!
   TBranch        *b_DST_EventHeader_EvtSequence;   //!
   TBranch        *b_DST_EventHeader_EvtType;   //!
   TBranch        *b_DST_EventHeader_TimeStamp;   //!
   TBranch        *b_DST_TrigLvl1_fUniqueID;   //!
   TBranch        *b_DST_TrigLvl1_fBits;   //!
   TBranch        *b_DST_TrigLvl1_lvl1_trigraw;   //!
   TBranch        *b_DST_TrigLvl1_lvl1_triglive;   //!
   TBranch        *b_DST_TrigLvl1_lvl1_trigscaled;   //!
   TBranch        *b_DST_TrigLvl1_lvl1_clock_cross;   //!
   TBranch        *b_DST_TrigLvl1_lvl1_rbits;   //!
   TBranch        *b_DST_TrigLvl1_beamclk;   //!
   TBranch        *b_DST_Sync_fUniqueID;   //!
   TBranch        *b_DST_Sync_fBits;   //!
   TBranch        *b_DST_Sync_eventcounter;   //!
   TBranch        *b_DST_Sync_eventnumber;   //!
   TBranch        *b_DST_Sync_runnumber;   //!
   TBranch        *b_DST_Sync_segmentnumber;   //!

   Final(TTree *tree=0);
   virtual ~Final();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Final_cxx
Final::Final(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/gpfs/mnt/gpfs02/phenix/plhf/plhf1/lbichon/taxi/Run14AuAu200MuonsMBPro109/17923/flat/merged_south.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/phenix/plhf/lbichon/taxi/Run14AuAu200MuonsMBPro109/17923/flat/merged_south.root");
      }
      f->GetObject("T",tree);

   }
   Init(tree);
}

Final::~Final()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Final::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Final::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Final::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("fUniqueID", &fUniqueID, &b_DST_COMPACTEPTREE_fUniqueID);
   fChain->SetBranchAddress("fBits", &fBits, &b_DST_COMPACTEPTREE_fBits);
   fChain->SetBranchAddress("evt_cent", &evt_cent, &b_DST_COMPACTEPTREE_evt_cent);
   fChain->SetBranchAddress("evt_bbcz", &evt_bbcz, &b_DST_COMPACTEPTREE_evt_bbcz);
   fChain->SetBranchAddress("evt_trig", &evt_trig, &b_DST_COMPACTEPTREE_evt_trig);
   fChain->SetBranchAddress("CompactEPArray", &CompactEPArray_, &b_DST_COMPACTEPTREE_CompactEPArray_);
   fChain->SetBranchAddress("CompactEPArray.fUniqueID", CompactEPArray_fUniqueID, &b_CompactEPArray_fUniqueID);
   fChain->SetBranchAddress("CompactEPArray.fBits", CompactEPArray_fBits, &b_CompactEPArray_fBits);
   fChain->SetBranchAddress("CompactEPArray.idcode", CompactEPArray_idcode, &b_CompactEPArray_idcode);
   fChain->SetBranchAddress("CompactEPArray.psi", CompactEPArray_psi, &b_CompactEPArray_psi);
//    fChain->SetBranchAddress("fUniqueID", &fUniqueID, &b_DST/DiMuonContainer_fUniqueID);
//    fChain->SetBranchAddress("fBits", &fBits, &b_DST/DiMuonContainer_fBits);
   fChain->SetBranchAddress("nDiMuons", &nDiMuons, &b_DST_DiMuonContainer_nDiMuons);
   fChain->SetBranchAddress("DiMuons", &DiMuons_, &b_DST_DiMuonContainer_DiMuons_);
   fChain->SetBranchAddress("DiMuons.fUniqueID", DiMuons_fUniqueID, &b_DiMuons_fUniqueID);
   fChain->SetBranchAddress("DiMuons.fBits", DiMuons_fBits, &b_DiMuons_fBits);
   fChain->SetBranchAddress("DiMuons.mass", DiMuons_mass, &b_DiMuons_mass);
   fChain->SetBranchAddress("DiMuons.charge", DiMuons_charge, &b_DiMuons_charge);
   fChain->SetBranchAddress("DiMuons.same_event", DiMuons_same_event, &b_DiMuons_same_event);
   fChain->SetBranchAddress("DiMuons.rapidity", DiMuons_rapidity, &b_DiMuons_rapidity);
   fChain->SetBranchAddress("DiMuons.X0", DiMuons_X0, &b_DiMuons_X0);
   fChain->SetBranchAddress("DiMuons.Y0", DiMuons_Y0, &b_DiMuons_Y0);
   fChain->SetBranchAddress("DiMuons.Z0", DiMuons_Z0, &b_DiMuons_Z0);
   fChain->SetBranchAddress("DiMuons.Px", DiMuons_Px, &b_DiMuons_Px);
   fChain->SetBranchAddress("DiMuons.Py", DiMuons_Py, &b_DiMuons_Py);
   fChain->SetBranchAddress("DiMuons.Pz", DiMuons_Pz, &b_DiMuons_Pz);
   fChain->SetBranchAddress("DiMuons.phi_dca", DiMuons_phi_dca, &b_DiMuons_phi_dca);
   fChain->SetBranchAddress("DiMuons.dca_r", DiMuons_dca_r, &b_DiMuons_dca_r);
   fChain->SetBranchAddress("DiMuons.dca_z", DiMuons_dca_z, &b_DiMuons_dca_z);
   fChain->SetBranchAddress("DiMuons.Evt_vtxchi2", DiMuons_Evt_vtxchi2, &b_DiMuons_Evt_vtxchi2);
   fChain->SetBranchAddress("DiMuons.Evt_vtxoor", DiMuons_Evt_vtxoor, &b_DiMuons_Evt_vtxoor);
   fChain->SetBranchAddress("DiMuons.costhCS", DiMuons_costhCS, &b_DiMuons_costhCS);
   fChain->SetBranchAddress("DiMuons.costhGJ", DiMuons_costhGJ, &b_DiMuons_costhGJ);
   fChain->SetBranchAddress("DiMuons.costhHX", DiMuons_costhHX, &b_DiMuons_costhHX);
   fChain->SetBranchAddress("DiMuons.phiCS", DiMuons_phiCS, &b_DiMuons_phiCS);
   fChain->SetBranchAddress("DiMuons.phiGJ", DiMuons_phiGJ, &b_DiMuons_phiGJ);
   fChain->SetBranchAddress("DiMuons.phiHX", DiMuons_phiHX, &b_DiMuons_phiHX);
   fChain->SetBranchAddress("DiMuons.Tr0_px", DiMuons_Tr0_px, &b_DiMuons_Tr0_px);
   fChain->SetBranchAddress("DiMuons.Tr0_py", DiMuons_Tr0_py, &b_DiMuons_Tr0_py);
   fChain->SetBranchAddress("DiMuons.Tr0_pz", DiMuons_Tr0_pz, &b_DiMuons_Tr0_pz);
   fChain->SetBranchAddress("DiMuons.Tr0_rapidity", DiMuons_Tr0_rapidity, &b_DiMuons_Tr0_rapidity);
   fChain->SetBranchAddress("DiMuons.Tr0_trhits", DiMuons_Tr0_trhits, &b_DiMuons_Tr0_trhits);
   fChain->SetBranchAddress("DiMuons.Tr0_idhits", DiMuons_Tr0_idhits, &b_DiMuons_Tr0_idhits);
   fChain->SetBranchAddress("DiMuons.Tr0_DG0", DiMuons_Tr0_DG0, &b_DiMuons_Tr0_DG0);
   fChain->SetBranchAddress("DiMuons.Tr0_DDG0", DiMuons_Tr0_DDG0, &b_DiMuons_Tr0_DDG0);
   fChain->SetBranchAddress("DiMuons.Tr0_DS3", DiMuons_Tr0_DS3, &b_DiMuons_Tr0_DS3);
   fChain->SetBranchAddress("DiMuons.Tr0_trchi2", DiMuons_Tr0_trchi2, &b_DiMuons_Tr0_trchi2);
   fChain->SetBranchAddress("DiMuons.Tr0_idchi2", DiMuons_Tr0_idchi2, &b_DiMuons_Tr0_idchi2);
   fChain->SetBranchAddress("DiMuons.Tr0_ntrhits", DiMuons_Tr0_ntrhits, &b_DiMuons_Tr0_ntrhits);
   fChain->SetBranchAddress("DiMuons.Tr0_nidhits", DiMuons_Tr0_nidhits, &b_DiMuons_Tr0_nidhits);
   fChain->SetBranchAddress("DiMuons.Tr0_lastgap", DiMuons_Tr0_lastgap, &b_DiMuons_Tr0_lastgap);
   fChain->SetBranchAddress("DiMuons.Tr0_xst1", DiMuons_Tr0_xst1, &b_DiMuons_Tr0_xst1);
   fChain->SetBranchAddress("DiMuons.Tr0_xst2", DiMuons_Tr0_xst2, &b_DiMuons_Tr0_xst2);
   fChain->SetBranchAddress("DiMuons.Tr0_xst3", DiMuons_Tr0_xst3, &b_DiMuons_Tr0_xst3);
   fChain->SetBranchAddress("DiMuons.Tr0_yst1", DiMuons_Tr0_yst1, &b_DiMuons_Tr0_yst1);
   fChain->SetBranchAddress("DiMuons.Tr0_yst2", DiMuons_Tr0_yst2, &b_DiMuons_Tr0_yst2);
   fChain->SetBranchAddress("DiMuons.Tr0_yst3", DiMuons_Tr0_yst3, &b_DiMuons_Tr0_yst3);
   fChain->SetBranchAddress("DiMuons.Tr0_idx", DiMuons_Tr0_idx, &b_DiMuons_Tr0_idx);
   fChain->SetBranchAddress("DiMuons.Tr0_idy", DiMuons_Tr0_idy, &b_DiMuons_Tr0_idy);
   fChain->SetBranchAddress("DiMuons.Tr0_st1px", DiMuons_Tr0_st1px, &b_DiMuons_Tr0_st1px);
   fChain->SetBranchAddress("DiMuons.Tr0_st1py", DiMuons_Tr0_st1py, &b_DiMuons_Tr0_st1py);
   fChain->SetBranchAddress("DiMuons.Tr0_st1pz", DiMuons_Tr0_st1pz, &b_DiMuons_Tr0_st1pz);
   fChain->SetBranchAddress("DiMuons.Tr0_MUID1D", DiMuons_Tr0_MUID1D, &b_DiMuons_Tr0_MUID1D);
   fChain->SetBranchAddress("DiMuons.Tr0_MUID1S", DiMuons_Tr0_MUID1S, &b_DiMuons_Tr0_MUID1S);
   fChain->SetBranchAddress("DiMuons.Tr0_dca_z", DiMuons_Tr0_dca_z, &b_DiMuons_Tr0_dca_z);
   fChain->SetBranchAddress("DiMuons.Tr0_dca_r", DiMuons_Tr0_dca_r, &b_DiMuons_Tr0_dca_r);
   fChain->SetBranchAddress("DiMuons.Tr1_px", DiMuons_Tr1_px, &b_DiMuons_Tr1_px);
   fChain->SetBranchAddress("DiMuons.Tr1_py", DiMuons_Tr1_py, &b_DiMuons_Tr1_py);
   fChain->SetBranchAddress("DiMuons.Tr1_pz", DiMuons_Tr1_pz, &b_DiMuons_Tr1_pz);
   fChain->SetBranchAddress("DiMuons.Tr1_rapidity", DiMuons_Tr1_rapidity, &b_DiMuons_Tr1_rapidity);
   fChain->SetBranchAddress("DiMuons.Tr1_trhits", DiMuons_Tr1_trhits, &b_DiMuons_Tr1_trhits);
   fChain->SetBranchAddress("DiMuons.Tr1_idhits", DiMuons_Tr1_idhits, &b_DiMuons_Tr1_idhits);
   fChain->SetBranchAddress("DiMuons.Tr1_DG0", DiMuons_Tr1_DG0, &b_DiMuons_Tr1_DG0);
   fChain->SetBranchAddress("DiMuons.Tr1_DDG0", DiMuons_Tr1_DDG0, &b_DiMuons_Tr1_DDG0);
   fChain->SetBranchAddress("DiMuons.Tr1_DS3", DiMuons_Tr1_DS3, &b_DiMuons_Tr1_DS3);
   fChain->SetBranchAddress("DiMuons.Tr1_trchi2", DiMuons_Tr1_trchi2, &b_DiMuons_Tr1_trchi2);
   fChain->SetBranchAddress("DiMuons.Tr1_idchi2", DiMuons_Tr1_idchi2, &b_DiMuons_Tr1_idchi2);
   fChain->SetBranchAddress("DiMuons.Tr1_ntrhits", DiMuons_Tr1_ntrhits, &b_DiMuons_Tr1_ntrhits);
   fChain->SetBranchAddress("DiMuons.Tr1_nidhits", DiMuons_Tr1_nidhits, &b_DiMuons_Tr1_nidhits);
   fChain->SetBranchAddress("DiMuons.Tr1_lastgap", DiMuons_Tr1_lastgap, &b_DiMuons_Tr1_lastgap);
   fChain->SetBranchAddress("DiMuons.Tr1_xst1", DiMuons_Tr1_xst1, &b_DiMuons_Tr1_xst1);
   fChain->SetBranchAddress("DiMuons.Tr1_xst2", DiMuons_Tr1_xst2, &b_DiMuons_Tr1_xst2);
   fChain->SetBranchAddress("DiMuons.Tr1_xst3", DiMuons_Tr1_xst3, &b_DiMuons_Tr1_xst3);
   fChain->SetBranchAddress("DiMuons.Tr1_yst1", DiMuons_Tr1_yst1, &b_DiMuons_Tr1_yst1);
   fChain->SetBranchAddress("DiMuons.Tr1_yst2", DiMuons_Tr1_yst2, &b_DiMuons_Tr1_yst2);
   fChain->SetBranchAddress("DiMuons.Tr1_yst3", DiMuons_Tr1_yst3, &b_DiMuons_Tr1_yst3);
   fChain->SetBranchAddress("DiMuons.Tr1_idx", DiMuons_Tr1_idx, &b_DiMuons_Tr1_idx);
   fChain->SetBranchAddress("DiMuons.Tr1_idy", DiMuons_Tr1_idy, &b_DiMuons_Tr1_idy);
   fChain->SetBranchAddress("DiMuons.Tr1_st1px", DiMuons_Tr1_st1px, &b_DiMuons_Tr1_st1px);
   fChain->SetBranchAddress("DiMuons.Tr1_st1py", DiMuons_Tr1_st1py, &b_DiMuons_Tr1_st1py);
   fChain->SetBranchAddress("DiMuons.Tr1_st1pz", DiMuons_Tr1_st1pz, &b_DiMuons_Tr1_st1pz);
   fChain->SetBranchAddress("DiMuons.Tr1_MUID1D", DiMuons_Tr1_MUID1D, &b_DiMuons_Tr1_MUID1D);
   fChain->SetBranchAddress("DiMuons.Tr1_MUID1S", DiMuons_Tr1_MUID1S, &b_DiMuons_Tr1_MUID1S);
   fChain->SetBranchAddress("DiMuons.Tr1_dca_z", DiMuons_Tr1_dca_z, &b_DiMuons_Tr1_dca_z);
   fChain->SetBranchAddress("DiMuons.Tr1_dca_r", DiMuons_Tr1_dca_r, &b_DiMuons_Tr1_dca_r);
   fChain->SetBranchAddress("DiMuons.mass_fvtx", DiMuons_mass_fvtx, &b_DiMuons_mass_fvtx);
   fChain->SetBranchAddress("DiMuons.mass_fvtxmutr", DiMuons_mass_fvtxmutr, &b_DiMuons_mass_fvtxmutr);
   fChain->SetBranchAddress("DiMuons.Tr0_x0_fvtx", DiMuons_Tr0_x0_fvtx, &b_DiMuons_Tr0_x0_fvtx);
   fChain->SetBranchAddress("DiMuons.Tr0_y0_fvtx", DiMuons_Tr0_y0_fvtx, &b_DiMuons_Tr0_y0_fvtx);
   fChain->SetBranchAddress("DiMuons.Tr0_z0_fvtx", DiMuons_Tr0_z0_fvtx, &b_DiMuons_Tr0_z0_fvtx);
   fChain->SetBranchAddress("DiMuons.Tr0_px_fvtx", DiMuons_Tr0_px_fvtx, &b_DiMuons_Tr0_px_fvtx);
   fChain->SetBranchAddress("DiMuons.Tr0_py_fvtx", DiMuons_Tr0_py_fvtx, &b_DiMuons_Tr0_py_fvtx);
   fChain->SetBranchAddress("DiMuons.Tr0_pz_fvtx", DiMuons_Tr0_pz_fvtx, &b_DiMuons_Tr0_pz_fvtx);
   fChain->SetBranchAddress("DiMuons.Tr0_x0_fvtxmutr", DiMuons_Tr0_x0_fvtxmutr, &b_DiMuons_Tr0_x0_fvtxmutr);
   fChain->SetBranchAddress("DiMuons.Tr0_y0_fvtxmutr", DiMuons_Tr0_y0_fvtxmutr, &b_DiMuons_Tr0_y0_fvtxmutr);
   fChain->SetBranchAddress("DiMuons.Tr0_z0_fvtxmutr", DiMuons_Tr0_z0_fvtxmutr, &b_DiMuons_Tr0_z0_fvtxmutr);
   fChain->SetBranchAddress("DiMuons.Tr0_px_fvtxmutr", DiMuons_Tr0_px_fvtxmutr, &b_DiMuons_Tr0_px_fvtxmutr);
   fChain->SetBranchAddress("DiMuons.Tr0_py_fvtxmutr", DiMuons_Tr0_py_fvtxmutr, &b_DiMuons_Tr0_py_fvtxmutr);
   fChain->SetBranchAddress("DiMuons.Tr0_pz_fvtxmutr", DiMuons_Tr0_pz_fvtxmutr, &b_DiMuons_Tr0_pz_fvtxmutr);
   fChain->SetBranchAddress("DiMuons.Tr0_nhits_fvtx", DiMuons_Tr0_nhits_fvtx, &b_DiMuons_Tr0_nhits_fvtx);
   fChain->SetBranchAddress("DiMuons.Tr0_dphi_fvtx", DiMuons_Tr0_dphi_fvtx, &b_DiMuons_Tr0_dphi_fvtx);
   fChain->SetBranchAddress("DiMuons.Tr0_dtheta_fvtx", DiMuons_Tr0_dtheta_fvtx, &b_DiMuons_Tr0_dtheta_fvtx);
   fChain->SetBranchAddress("DiMuons.Tr0_dr_fvtx", DiMuons_Tr0_dr_fvtx, &b_DiMuons_Tr0_dr_fvtx);
   fChain->SetBranchAddress("DiMuons.Tr0_chi2_fvtx", DiMuons_Tr0_chi2_fvtx, &b_DiMuons_Tr0_chi2_fvtx);
   fChain->SetBranchAddress("DiMuons.Tr0_chi2_fvtxmutr", DiMuons_Tr0_chi2_fvtxmutr, &b_DiMuons_Tr0_chi2_fvtxmutr);
   fChain->SetBranchAddress("DiMuons.Tr0_fvtx_strip[4]", DiMuons_Tr0_fvtx_strip, &b_DiMuons_Tr0_fvtx_strip);
   fChain->SetBranchAddress("DiMuons.Tr0_nfvtx_tracklets_cone", DiMuons_Tr0_nfvtx_tracklets_cone, &b_DiMuons_Tr0_nfvtx_tracklets_cone);
   fChain->SetBranchAddress("DiMuons.Tr0_nfvtx_clusters_cone", DiMuons_Tr0_nfvtx_clusters_cone, &b_DiMuons_Tr0_nfvtx_clusters_cone);
   fChain->SetBranchAddress("DiMuons.Tr0_dca_phi", DiMuons_Tr0_dca_phi, &b_DiMuons_Tr0_dca_phi);
   fChain->SetBranchAddress("DiMuons.Tr0_clusters_size1", DiMuons_Tr0_clusters_size1, &b_DiMuons_Tr0_clusters_size1);
   fChain->SetBranchAddress("DiMuons.Tr1_x0_fvtx", DiMuons_Tr1_x0_fvtx, &b_DiMuons_Tr1_x0_fvtx);
   fChain->SetBranchAddress("DiMuons.Tr1_y0_fvtx", DiMuons_Tr1_y0_fvtx, &b_DiMuons_Tr1_y0_fvtx);
   fChain->SetBranchAddress("DiMuons.Tr1_z0_fvtx", DiMuons_Tr1_z0_fvtx, &b_DiMuons_Tr1_z0_fvtx);
   fChain->SetBranchAddress("DiMuons.Tr1_px_fvtx", DiMuons_Tr1_px_fvtx, &b_DiMuons_Tr1_px_fvtx);
   fChain->SetBranchAddress("DiMuons.Tr1_py_fvtx", DiMuons_Tr1_py_fvtx, &b_DiMuons_Tr1_py_fvtx);
   fChain->SetBranchAddress("DiMuons.Tr1_pz_fvtx", DiMuons_Tr1_pz_fvtx, &b_DiMuons_Tr1_pz_fvtx);
   fChain->SetBranchAddress("DiMuons.Tr1_x0_fvtxmutr", DiMuons_Tr1_x0_fvtxmutr, &b_DiMuons_Tr1_x0_fvtxmutr);
   fChain->SetBranchAddress("DiMuons.Tr1_y0_fvtxmutr", DiMuons_Tr1_y0_fvtxmutr, &b_DiMuons_Tr1_y0_fvtxmutr);
   fChain->SetBranchAddress("DiMuons.Tr1_z0_fvtxmutr", DiMuons_Tr1_z0_fvtxmutr, &b_DiMuons_Tr1_z0_fvtxmutr);
   fChain->SetBranchAddress("DiMuons.Tr1_px_fvtxmutr", DiMuons_Tr1_px_fvtxmutr, &b_DiMuons_Tr1_px_fvtxmutr);
   fChain->SetBranchAddress("DiMuons.Tr1_py_fvtxmutr", DiMuons_Tr1_py_fvtxmutr, &b_DiMuons_Tr1_py_fvtxmutr);
   fChain->SetBranchAddress("DiMuons.Tr1_pz_fvtxmutr", DiMuons_Tr1_pz_fvtxmutr, &b_DiMuons_Tr1_pz_fvtxmutr);
   fChain->SetBranchAddress("DiMuons.Tr1_nhits_fvtx", DiMuons_Tr1_nhits_fvtx, &b_DiMuons_Tr1_nhits_fvtx);
   fChain->SetBranchAddress("DiMuons.Tr1_dphi_fvtx", DiMuons_Tr1_dphi_fvtx, &b_DiMuons_Tr1_dphi_fvtx);
   fChain->SetBranchAddress("DiMuons.Tr1_dtheta_fvtx", DiMuons_Tr1_dtheta_fvtx, &b_DiMuons_Tr1_dtheta_fvtx);
   fChain->SetBranchAddress("DiMuons.Tr1_dr_fvtx", DiMuons_Tr1_dr_fvtx, &b_DiMuons_Tr1_dr_fvtx);
   fChain->SetBranchAddress("DiMuons.Tr1_chi2_fvtx", DiMuons_Tr1_chi2_fvtx, &b_DiMuons_Tr1_chi2_fvtx);
   fChain->SetBranchAddress("DiMuons.Tr1_chi2_fvtxmutr", DiMuons_Tr1_chi2_fvtxmutr, &b_DiMuons_Tr1_chi2_fvtxmutr);
   fChain->SetBranchAddress("DiMuons.Tr1_fvtx_strip[4]", DiMuons_Tr1_fvtx_strip, &b_DiMuons_Tr1_fvtx_strip);
   fChain->SetBranchAddress("DiMuons.Tr1_nfvtx_tracklets_cone", DiMuons_Tr1_nfvtx_tracklets_cone, &b_DiMuons_Tr1_nfvtx_tracklets_cone);
   fChain->SetBranchAddress("DiMuons.Tr1_nfvtx_clusters_cone", DiMuons_Tr1_nfvtx_clusters_cone, &b_DiMuons_Tr1_nfvtx_clusters_cone);
   fChain->SetBranchAddress("DiMuons.Tr1_dca_phi", DiMuons_Tr1_dca_phi, &b_DiMuons_Tr1_dca_phi);
   fChain->SetBranchAddress("DiMuons.Tr1_clusters_size1", DiMuons_Tr1_clusters_size1, &b_DiMuons_Tr1_clusters_size1);
   fChain->SetBranchAddress("DiMuons.Px_fvtxmutr", DiMuons_Px_fvtxmutr, &b_DiMuons_Px_fvtxmutr);
   fChain->SetBranchAddress("DiMuons.Py_fvtxmutr", DiMuons_Py_fvtxmutr, &b_DiMuons_Py_fvtxmutr);
   fChain->SetBranchAddress("DiMuons.Pz_fvtxmutr", DiMuons_Pz_fvtxmutr, &b_DiMuons_Pz_fvtxmutr);
   fChain->SetBranchAddress("DiMuons.rapidity_fvtxmutr", DiMuons_rapidity_fvtxmutr, &b_DiMuons_rapidity_fvtxmutr);
   fChain->SetBranchAddress("DiMuons.Evt_vtxchi2_fvtxmutr", DiMuons_Evt_vtxchi2_fvtxmutr, &b_DiMuons_Evt_vtxchi2_fvtxmutr);
   fChain->SetBranchAddress("DiMuons.X0_fvtxmutr", DiMuons_X0_fvtxmutr, &b_DiMuons_X0_fvtxmutr);
   fChain->SetBranchAddress("DiMuons.Y0_fvtxmutr", DiMuons_Y0_fvtxmutr, &b_DiMuons_Y0_fvtxmutr);
   fChain->SetBranchAddress("DiMuons.Z0_fvtxmutr", DiMuons_Z0_fvtxmutr, &b_DiMuons_Z0_fvtxmutr);
   fChain->SetBranchAddress("DiMuons.X0_fvtx", DiMuons_X0_fvtx, &b_DiMuons_X0_fvtx);
   fChain->SetBranchAddress("DiMuons.Y0_fvtx", DiMuons_Y0_fvtx, &b_DiMuons_Y0_fvtx);
   fChain->SetBranchAddress("DiMuons.Z0_fvtx", DiMuons_Z0_fvtx, &b_DiMuons_Z0_fvtx);
   fChain->SetBranchAddress("DiMuons.Tr0_x0", DiMuons_Tr0_x0, &b_DiMuons_Tr0_x0);
   fChain->SetBranchAddress("DiMuons.Tr1_x0", DiMuons_Tr1_x0, &b_DiMuons_Tr1_x0);
   fChain->SetBranchAddress("DiMuons.Tr0_y0", DiMuons_Tr0_y0, &b_DiMuons_Tr0_y0);
   fChain->SetBranchAddress("DiMuons.Tr1_y0", DiMuons_Tr1_y0, &b_DiMuons_Tr1_y0);
   fChain->SetBranchAddress("DiMuons.Tr0_n_matchings", DiMuons_Tr0_n_matchings, &b_DiMuons_Tr0_n_matchings);
   fChain->SetBranchAddress("DiMuons.Tr1_n_matchings", DiMuons_Tr1_n_matchings, &b_DiMuons_Tr1_n_matchings);
   fChain->SetBranchAddress("DiMuons.Tr0_vtx_index", DiMuons_Tr0_vtx_index, &b_DiMuons_Tr0_vtx_index);
   fChain->SetBranchAddress("DiMuons.Tr1_vtx_index", DiMuons_Tr1_vtx_index, &b_DiMuons_Tr1_vtx_index);
   fChain->SetBranchAddress("DiMuons.Tr0_hit_pattern", DiMuons_Tr0_hit_pattern, &b_DiMuons_Tr0_hit_pattern);
   fChain->SetBranchAddress("DiMuons.Tr1_hit_pattern", DiMuons_Tr1_hit_pattern, &b_DiMuons_Tr1_hit_pattern);
   fChain->SetBranchAddress("DiMuons.Tr0_track_id", DiMuons_Tr0_track_id, &b_DiMuons_Tr0_track_id);
   fChain->SetBranchAddress("DiMuons.Tr1_track_id", DiMuons_Tr1_track_id, &b_DiMuons_Tr1_track_id);
   fChain->SetBranchAddress("DiMuons.Tr0_maxres_sigma", DiMuons_Tr0_maxres_sigma, &b_DiMuons_Tr0_maxres_sigma);
   fChain->SetBranchAddress("DiMuons.Tr1_maxres_sigma", DiMuons_Tr1_maxres_sigma, &b_DiMuons_Tr1_maxres_sigma);
   fChain->SetBranchAddress("DiMuons.Tr0_is_sfvtx", DiMuons_Tr0_is_sfvtx, &b_DiMuons_Tr0_is_sfvtx);
   fChain->SetBranchAddress("DiMuons.Tr1_is_sfvtx", DiMuons_Tr1_is_sfvtx, &b_DiMuons_Tr1_is_sfvtx);
   fChain->SetBranchAddress("DiMuons.Tr0_best_fvtxmutr_match", DiMuons_Tr0_best_fvtxmutr_match, &b_DiMuons_Tr0_best_fvtxmutr_match);
   fChain->SetBranchAddress("DiMuons.Tr1_best_fvtxmutr_match", DiMuons_Tr1_best_fvtxmutr_match, &b_DiMuons_Tr1_best_fvtxmutr_match);
   fChain->SetBranchAddress("DiMuons.Tr0_x_fvtxproj", DiMuons_Tr0_x_fvtxproj, &b_DiMuons_Tr0_x_fvtxproj);
   fChain->SetBranchAddress("DiMuons.Tr0_y_fvtxproj", DiMuons_Tr0_y_fvtxproj, &b_DiMuons_Tr0_y_fvtxproj);
   fChain->SetBranchAddress("DiMuons.Tr1_x_fvtxproj", DiMuons_Tr1_x_fvtxproj, &b_DiMuons_Tr1_x_fvtxproj);
   fChain->SetBranchAddress("DiMuons.Tr1_y_fvtxproj", DiMuons_Tr1_y_fvtxproj, &b_DiMuons_Tr1_y_fvtxproj);
   fChain->SetBranchAddress("DiMuons.Tr0_idpanel", DiMuons_Tr0_idpanel, &b_DiMuons_Tr0_idpanel);
   fChain->SetBranchAddress("DiMuons.Tr1_idpanel", DiMuons_Tr1_idpanel, &b_DiMuons_Tr1_idpanel);
   fChain->SetBranchAddress("Evt_vtxX", &Evt_vtxX, &b_DST_DiMuonContainer_Evt_vtxX);
   fChain->SetBranchAddress("Evt_vtxY", &Evt_vtxY, &b_DST_DiMuonContainer_Evt_vtxY);
   fChain->SetBranchAddress("Evt_vtxZ", &Evt_vtxZ, &b_DST_DiMuonContainer_Evt_vtxZ);
   fChain->SetBranchAddress("Evt_vtxX_Err", &Evt_vtxX_Err, &b_DST_DiMuonContainer_Evt_vtxX_Err);
   fChain->SetBranchAddress("Evt_vtxY_Err", &Evt_vtxY_Err, &b_DST_DiMuonContainer_Evt_vtxY_Err);
   fChain->SetBranchAddress("Evt_vtxZ_Err", &Evt_vtxZ_Err, &b_DST_DiMuonContainer_Evt_vtxZ_Err);
   fChain->SetBranchAddress("Evt_fvtxX", &Evt_fvtxX, &b_DST_DiMuonContainer_Evt_fvtxX);
   fChain->SetBranchAddress("Evt_fvtxY", &Evt_fvtxY, &b_DST_DiMuonContainer_Evt_fvtxY);
   fChain->SetBranchAddress("Evt_fvtxZ", &Evt_fvtxZ, &b_DST_DiMuonContainer_Evt_fvtxZ);
   fChain->SetBranchAddress("Evt_fvtxX_Err", &Evt_fvtxX_Err, &b_DST_DiMuonContainer_Evt_fvtxX_Err);
   fChain->SetBranchAddress("Evt_fvtxY_Err", &Evt_fvtxY_Err, &b_DST_DiMuonContainer_Evt_fvtxY_Err);
   fChain->SetBranchAddress("Evt_fvtxZ_Err", &Evt_fvtxZ_Err, &b_DST_DiMuonContainer_Evt_fvtxZ_Err);
   fChain->SetBranchAddress("Evt_fvtxX2", &Evt_fvtxX2, &b_DST_DiMuonContainer_Evt_fvtxX2);
   fChain->SetBranchAddress("Evt_fvtxY2", &Evt_fvtxY2, &b_DST_DiMuonContainer_Evt_fvtxY2);
   fChain->SetBranchAddress("Evt_fvtxZ2", &Evt_fvtxZ2, &b_DST_DiMuonContainer_Evt_fvtxZ2);
   fChain->SetBranchAddress("Evt_bbcZ", &Evt_bbcZ, &b_DST_DiMuonContainer_Evt_bbcZ);
   fChain->SetBranchAddress("Evt_bbcZ_Err", &Evt_bbcZ_Err, &b_DST_DiMuonContainer_Evt_bbcZ_Err);
   fChain->SetBranchAddress("Evt_Cent", &Evt_Cent, &b_DST_DiMuonContainer_Evt_Cent);
   fChain->SetBranchAddress("Evt_Mult_FVTXS", &Evt_Mult_FVTXS, &b_DST_DiMuonContainer_Evt_Mult_FVTXS);
   fChain->SetBranchAddress("Evt_Mult_FVTXN", &Evt_Mult_FVTXN, &b_DST_DiMuonContainer_Evt_Mult_FVTXN);
   fChain->SetBranchAddress("Evt_Mult_sFVTXS", &Evt_Mult_sFVTXS, &b_DST_DiMuonContainer_Evt_Mult_sFVTXS);
   fChain->SetBranchAddress("Evt_Mult_sFVTXN", &Evt_Mult_sFVTXN, &b_DST_DiMuonContainer_Evt_Mult_sFVTXN);
   fChain->SetBranchAddress("Evt_Mult_SVX", &Evt_Mult_SVX, &b_DST_DiMuonContainer_Evt_Mult_SVX);
   fChain->SetBranchAddress("Evt_BbcTdcMean_S", &Evt_BbcTdcMean_S, &b_DST_DiMuonContainer_Evt_BbcTdcMean_S);
   fChain->SetBranchAddress("Evt_BbcTdcMean_N", &Evt_BbcTdcMean_N, &b_DST_DiMuonContainer_Evt_BbcTdcMean_N);
   fChain->SetBranchAddress("Evt_BbcTdcRMS_S", &Evt_BbcTdcRMS_S, &b_DST_DiMuonContainer_Evt_BbcTdcRMS_S);
   fChain->SetBranchAddress("Evt_BbcTdcRMS_N", &Evt_BbcTdcRMS_N, &b_DST_DiMuonContainer_Evt_BbcTdcRMS_N);
   fChain->SetBranchAddress("Evt_BbcTdcMode_S", &Evt_BbcTdcMode_S, &b_DST_DiMuonContainer_Evt_BbcTdcMode_S);
   fChain->SetBranchAddress("Evt_BbcTdcMode_N", &Evt_BbcTdcMode_N, &b_DST_DiMuonContainer_Evt_BbcTdcMode_N);
   fChain->SetBranchAddress("Evt_BbcTdcnPeaks_S", &Evt_BbcTdcnPeaks_S, &b_DST_DiMuonContainer_Evt_BbcTdcnPeaks_S);
   fChain->SetBranchAddress("Evt_BbcTdcnPeaks_N", &Evt_BbcTdcnPeaks_N, &b_DST_DiMuonContainer_Evt_BbcTdcnPeaks_N);
//    fChain->SetBranchAddress("fUniqueID", &fUniqueID, &b_DST/EventHeader_fUniqueID);
//    fChain->SetBranchAddress("fBits", &fBits, &b_DST/EventHeader_fBits);
   fChain->SetBranchAddress("EvtSequence", &EvtSequence, &b_DST_EventHeader_EvtSequence);
   fChain->SetBranchAddress("EvtType", &EvtType, &b_DST_EventHeader_EvtType);
   fChain->SetBranchAddress("TimeStamp", &TimeStamp, &b_DST_EventHeader_TimeStamp);
//    fChain->SetBranchAddress("fUniqueID", &fUniqueID, &b_DST/TrigLvl1_fUniqueID);
//    fChain->SetBranchAddress("fBits", &fBits, &b_DST/TrigLvl1_fBits);
   fChain->SetBranchAddress("lvl1_trigraw", &lvl1_trigraw, &b_DST_TrigLvl1_lvl1_trigraw);
   fChain->SetBranchAddress("lvl1_triglive", &lvl1_triglive, &b_DST_TrigLvl1_lvl1_triglive);
   fChain->SetBranchAddress("lvl1_trigscaled", &lvl1_trigscaled, &b_DST_TrigLvl1_lvl1_trigscaled);
   fChain->SetBranchAddress("lvl1_clock_cross", &lvl1_clock_cross, &b_DST_TrigLvl1_lvl1_clock_cross);
   fChain->SetBranchAddress("lvl1_rbits[5]", lvl1_rbits, &b_DST_TrigLvl1_lvl1_rbits);
   fChain->SetBranchAddress("beamclk[2]", beamclk, &b_DST_TrigLvl1_beamclk);
//    fChain->SetBranchAddress("fUniqueID", &fUniqueID, &b_DST/Sync_fUniqueID);
//    fChain->SetBranchAddress("fBits", &fBits, &b_DST/Sync_fBits);
   fChain->SetBranchAddress("eventcounter", &eventcounter, &b_DST_Sync_eventcounter);
   fChain->SetBranchAddress("eventnumber", &eventnumber, &b_DST_Sync_eventnumber);
   fChain->SetBranchAddress("runnumber", &runnumber, &b_DST_Sync_runnumber);
   fChain->SetBranchAddress("segmentnumber", &segmentnumber, &b_DST_Sync_segmentnumber);
   Notify();
}

Bool_t Final::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Final::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Final::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Final_cxx
